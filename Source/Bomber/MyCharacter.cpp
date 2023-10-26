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

	//初始化地图部件
	mapComponent_ = CreateDefaultSubobject<UMapComponent>(TEXT("Map Component"));

	//设置 steletal
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
	//角色构造的时候会把自己在地图上更新位置
	Super::OnConstruction(Transform);
	if (ISVALID(mapComponent_) == false || ISTRANSIENT(this) == true)
		return;

	mapComponent_->UpdateSelfOnMap();

	if (ISVALID(GetRootComponent()) == true)
	{
		const float ACTOR_HEIGHT = GetRootComponent()->Bounds.BoxExtent.Z;//包围盒的z半径,也就是总高度的一半
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
		//放置炸弹 自身可用的炸弹数量减少
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

