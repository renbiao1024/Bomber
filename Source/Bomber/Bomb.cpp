// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"
#include "Bomber.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "MyCharacter.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mapComponent_ = CreateDefaultSubobject<UMapComponent>(TEXT("Map Component"));
	bombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bomb Mesh"));
	const TArray<TCHAR*> pathes{
		TEXT("/Game/Bomber/Materials/MI_Bombs/MI_Bomb_Blue.MI_Bomb_Blue"),
		TEXT("/Game/Bomber/Materials/MI_Bombs/MI_Bomb_Blue.MI_Bomb_Yellow"),
		TEXT("/Game/Bomber/Materials/MI_Bombs/MI_Bomb_Blue.MI_Bomb_Silver"),
		TEXT("/Game/Bomber/Materials/MI_Bombs/MI_Bomb_Blue.MI_Bomb_Pink"),
	};

	for (const auto& path : pathes)
	{
		ConstructorHelpers::FObjectFinder<UMaterialInterface> materialFinder(path);
		if (materialFinder.Succeeded())
		{
			bombMaterials_.Add(materialFinder.Object);
		}
	}
}

void ABomb::InitializeBombProperties(int32* outBombN, const int32& fireN, const int32& characterID)
{
	characterBombN_ = outBombN;
	characterFireN_ = fireN;

	const int32 BOMB_MATERIAL_NO = characterID % bombMaterials_.Num();
	bombMesh->SetMaterial(0, bombMaterials_[BOMB_MATERIAL_NO]);
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(lifeSpan_);
}

void ABomb::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (ISVALID(mapComponent_) == false || ISTRANSIENT(this) == true)
		return;
	mapComponent_->UpdateSelfOnMap();
}

void ABomb::Destroyed()
{
	Super::Destroyed();
	if (characterBombN_ != nullptr)
	{
		//炸弹销毁 玩家可用炸弹数增加
		(*characterBombN_)++;
	}
}

void ABomb::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
}


