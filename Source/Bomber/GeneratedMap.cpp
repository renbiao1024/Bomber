// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedMap.h"
#include "Bomber.h"


FCell::FCell(const FVector& cellLocation) : location(cellLocation)
{
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
			foundedCell = i.Key;
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

AActor* AGeneratedMap::AddActorOnMap_Implementation(const FCell& cell, AActor* updateActor, EActorTypeEnum actorType)
{
	return nullptr;
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
	if (IsValid(USingletonLibrary::GetSingleton()->levelMap) == false)
		USingletonLibrary::GetSingleton()->levelMap = this;
	GeneratedMap_.Empty();
	return true;
}
