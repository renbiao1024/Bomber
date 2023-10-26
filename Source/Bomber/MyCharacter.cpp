// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Bomber.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//初始化地图部件
	mapComponent = CreateDefaultSubobject<UMapComponent>("Map Component");
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
	if (!ISVALID(USingletonLibrary::GetLevelMap())) return;
	mapComponent->UpdateSelfOnMap();
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

