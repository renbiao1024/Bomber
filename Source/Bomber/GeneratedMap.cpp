// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedMap.h"
#include "Bomber.h"


FCell::FCell(const AActor* actor)
{
	if (!ISVALID(actor) || ISVALID(USingletonLibrary::GetLevelMap())) return;

	//没有地图元素
	if (USingletonLibrary::GetLevelMap()->GeneratedMap_.Num() == 0) return;

	for (int32 i = 0; i < 3; ++i)
	{
		switch (i)
		{
		case 0:
			//原始位置
			location = actor->GetActorLocation();
			break;
		case 1:
			//GridSnap函数返回一个新的FVector对象，这个对象是原向量对齐到网格后的结果。
			location = actor->GetActorLocation().GridSnap(USingletonLibrary::GetFloorLength());
			break;
		case 2:
			FCell foundedCell;
			//当前Cell的位置是已知的地图中距离自己最近的地图cell的location
			for (const auto& j : USingletonLibrary::GetLevelMap()->GeneratedMap_)
			{
				if (USingletonLibrary::CalculateCellsLength(j.Key, *this) < USingletonLibrary::CalculateCellsLength(foundedCell, *this))
				{
					foundedCell.location = j.Key.location;
				}
			}
			location = foundedCell.location;
			break;
		}
	}

	if (USingletonLibrary::GetLevelMap()->GeneratedMap_.Contains(*this) && !IsValid(*USingletonLibrary::GetLevelMap()->GeneratedMap_.Find(*this)))
	{
		return;
	}
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

void AGeneratedMap::AddActorOnMapByObj_Implementation(const AActor* updateActor)
{
}

// Called when the game starts or when spawned
void AGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
}

void AGeneratedMap::OnConstruction(const FTransform& Transform)
{
	if (!ISVALID(USingletonLibrary::GetSingleton()))
		return;
	if (!ISVALID(USingletonLibrary::GetLevelMap()))
		USingletonLibrary::GetSingleton()->levelMap_ = this;
	GenerateLevelMap();
}

void AGeneratedMap::GenerateLevelMap_Implementation()
{
	GeneratedMap_.Empty();
	charactersOnMap_.Empty();
}
