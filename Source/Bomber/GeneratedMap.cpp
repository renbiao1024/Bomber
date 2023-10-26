// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedMap.h"
#include "Bomber.h"


FCell::FCell(const AActor* actor)
{
	if (!ISVALID(actor) || ISVALID(USingletonLibrary::GetLevelMap())) return;

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

void AGeneratedMap::DestroyActorFromMap_Implementation(const FCell& cell)
{
}

AActor* AGeneratedMap::AddActorOnMap_Implementation(const FCell& cell, EActorTypeEnum actorType)
{
	return nullptr;
}

void AGeneratedMap::AddActorOnMapByObj_Implementation(const FCell& cell, const AActor* updateActor)
{
}

// Called when the game starts or when spawned
void AGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
}

void AGeneratedMap::OnConstruction(const FTransform& Transform)
{
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
	if (!ISVALID(USingletonLibrary::GetSingleton()))
		return;
	if (!ISVALID(USingletonLibrary::GetLevelMap()))
		USingletonLibrary::GetSingleton()->levelMap_ = this;
	GeneratedMap_.Empty();
	charactersOnMap_.Empty();
}
