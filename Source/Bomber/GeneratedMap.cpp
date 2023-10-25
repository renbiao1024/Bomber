// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedMap.h"
#include "Bomber.h"


FCell::FCell(const AActor* actor)
{
	CHECKMAP();
	if (IsValid(actor) == false) return;
	//Cell的位置设置为Actor的位置
	this->location = actor->GetActorLocation();
	//没有地图元素
	if (USingletonLibrary::GetLevelMap()->GeneratedMap_.Num() == 0) return;

	if (USingletonLibrary::GetLevelMap()->GeneratedMap_.Contains(*this))
	{
		return;
	}

	FCell foundedCell;
	//当前Cell的位置是地图中距离自己最近的cell的location
	for (auto i : USingletonLibrary::GetLevelMap()->GeneratedMap_)
	{
		if (USingletonLibrary::CalculateCellsLength(i.Key, *this) < USingletonLibrary::CalculateCellsLength(foundedCell, *this))
		{
			foundedCell.location = i.Key.location;
		}
	}
	this->location = foundedCell.location;
}

// Sets default values
AGeneratedMap::AGeneratedMap()
{

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

bool AGeneratedMap::DestroyActorFromMap_Implementation(const FCell& cell)
{
	return true;
}

AActor* AGeneratedMap::AddActorOnMap_Implementation(const FCell& cell, EActorTypeEnum actorType)
{
	return nullptr;
}

void AGeneratedMap::AddActorOnMapByObj_Implementation(const AActor* updateActor)
{
}

// Called when the game starts or when spawned
void AGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
}

bool AGeneratedMap::GenerateLevelMap_Implementation()
{
	if (IsValid(USingletonLibrary::GetSingleton()) == false)
		return false;
	if (IsValid(USingletonLibrary::GetLevelMap()) == false)
		USingletonLibrary::GetSingleton()->levelMap_ = this;
	GeneratedMap_.Empty();
	charactersOnMap_.Empty();
	return true;
}
