// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Bomb.h"
#include "Bomber.h"
#include "Components/SkeletalMeshComponent.h"
#include "GeneratedMap.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//��ʼ����ͼ����
	mapComponent_ = CreateDefaultSubobject<UMapComponent>(TEXT("Map Component"));

	//���� steletal
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMeshFinder(TEXT("TODO PATH OF skeletalMesh"));
	if (skeletalMeshFinder.Succeeded() && ISVALID(GetMesh()))
	{
		GetMesh()->SetSkeletalMesh(skeletalMeshFinder.Object);
		GetMesh()->SetWorldLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMyCharacter::OnConstruction(const FTransform& Transform)
{
	//��ɫ�����ʱ�����Լ��ڵ�ͼ�ϸ���λ��
	Super::OnConstruction(Transform);
	if (ISVALID(mapComponent_) == false || ISTRANSIENT(this) == true)
		return;

	mapComponent_->UpdateSelfOnMap();

	if (ISVALID(GetRootComponent()) == true)
	{
		const float ACTOR_HEIGHT = GetRootComponent()->Bounds.BoxExtent.Z;//��Χ�е�z�뾶,Ҳ�����ܸ߶ȵ�һ��
		//GetRootComponent()->AddRelativeLocation(FVector(0, 0, ACTOR_HEIGHT));
	}
}

void AMyCharacter::SpawnBomb()
{
	if (powerups_.fireN == 0 || HasActorBegunPlay() == false)
		return;

	ABomb* const bomb = Cast<ABomb>(USingletonLibrary::GetLevelMap()->AddActorOnMap(FCell(this), EActorTypeEnum::Bomb));
	if (bomb != nullptr)
	{
		//����ը�� ������õ�ը����������
		bomb->InitializeBombProperties(&powerups_.bombN, powerups_.fireN, characterID_);
		powerups_.bombN--;
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("SpawnEvent", EInputEvent::IE_Pressed, this, &AMyCharacter::SpawnBomb);
}

