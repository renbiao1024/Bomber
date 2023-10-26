// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedMap.h"
#include "Bomber.h"


FCell::FCell(const AActor* actor)
{
	if (!ISVALID(actor) || ISVALID(USingletonLibrary::GetLevelMap()) || ISTRANSIENT(actor))
		return;

	//没有地图元素
	if (USingletonLibrary::GetLevelMap()->GeneratedMap_.Num() == 0) return;

	location = USingletonLibrary::GetLevelMap()->GetNearestCell(actor).location;
}

// Sets default values
AGeneratedMap::AGeneratedMap()
{
	//拖动中不构造脚本，拖动结束才构造
	bRunConstructionScriptOnDrag = false;
}

TSet<FCell> AGeneratedMap::GetSidesCells_Implementation(const FCell& cell, int32 sideLength, EPathTypesEnum pathfinder) const
{
	TSet<FCell> foundedLocations;
	return foundedLocations;
}

TSet<FCell> AGeneratedMap::FilterCellsByTypes_Implementation(const TSet<FCell>& keys, const TArray<EActorTypeEnum>& filterTypes, const ACharacter* excludePlayer) const
{
	TSet<FCell> foundedLocations;
	return foundedLocations;
}

AActor* AGeneratedMap::AddActorOnMap_Implementation(const FCell& cell, EActorTypeEnum actorType)
{
	return nullptr;
}


void AGeneratedMap::AddActorOnMapByObj_Implementation(const FCell& cell, const AActor* updateActor)
{
	if (ISVALID(updateActor) == false || !GeneratedMap_.Contains(cell) || ISTRANSIENT(updateActor))
		return;


	const ACharacter* updateCharacter = Cast<ACharacter>(updateActor);
	if (updateCharacter != nullptr)	//角色
	{
		charactersOnMap_.Add(updateCharacter);
	}
	else //其他actor
	{
		//通过 value 找 key
		const FCell* cellOfExistingActor = GeneratedMap_.FindKey(updateActor);
		if (cellOfExistingActor != nullptr && cellOfExistingActor->location != cell.location)
		{
			GeneratedMap_.Remove(*cellOfExistingActor);
		}
		GeneratedMap_.Add(cell, updateActor);
	}
}

void AGeneratedMap::DestroyActorsFromMap_Implementation(const FCell& cell)
{
}

// Called when the game starts or when spawned
void AGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
	USingletonLibrary::SetLevelMap(this);
	USingletonLibrary::GetLevelMap()->charactersOnMap_.Compact();
	USingletonLibrary::GetLevelMap()->charactersOnMap_.Shrink();
}

void AGeneratedMap::OnConstruction(const FTransform& Transform)
{
	if (ISTRANSIENT(this) == true)
		return;
	GenerateLevelMap();
}

void AGeneratedMap::Destroyed()
{
	TArray<AActor*> attachedActors;
	GetAttachedActors(attachedActors);
	for (auto* attachedActor : attachedActors)
	{
		attachedActor->Destroy();
	}
	Super::Destroyed();
}

void AGeneratedMap::GenerateLevelMap_Implementation()
{
	USingletonLibrary::SetLevelMap(this);
	GeneratedMap_.Empty();
	charactersOnMap_.Empty();
}
