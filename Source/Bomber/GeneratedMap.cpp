// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratedMap.h"
#include "Bomber.h"
#include "Cell.h"
#include "GameFramework/Character.h"

// Sets default values
AGeneratedMap::AGeneratedMap()
{
	//�϶��в�����ű����϶������Ź���
	bRunConstructionScriptOnDrag = false;
}

TSet<FCell> AGeneratedMap::GetSidesCells_Implementation(const FCell& cell, int32 sideLength, EPathTypesEnum pathfinder) const
{
	TSet<FCell> foundedLocations;
	return foundedLocations;
}

AActor* AGeneratedMap::AddActorOnMap_Implementation(const FCell& cell, EActorTypeEnum actorType)
{
	return nullptr;
}

TSet<FCell> AGeneratedMap::FilterCellsByTypes_Implementation(const TSet<FCell>& keys, TArray<EActorTypeEnum>& filterTypes, const ACharacter* excludePlayer) const
{
	TSet<FCell> foundedLocations;
	return foundedLocations;
}

void AGeneratedMap::AddActorOnMapByObj_Implementation(const FCell& cell, const AActor* updateActor)
{
	if (ISVALID(updateActor) == false || !GeneratedMap_.Contains(cell) || ISTRANSIENT(updateActor))
		return;


	const ACharacter* updateCharacter = Cast<ACharacter>(updateActor);
	if (updateCharacter != nullptr)	//��ɫ
	{
		charactersOnMap_.Add(updateCharacter);
	}
	else //����actor
	{
		//ͨ�� value �� key
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
