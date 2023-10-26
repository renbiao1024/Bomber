// Fill out your copyright notice in the Description page of Project Settings.


#include "MapComponent.h"
#include "Bomber.h"

// Sets default values for this component's properties
UMapComponent::UMapComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMapComponent::UpdateSelfOnMap()
{
	if (!ISVALID(owner) || !ISVALID(USingletonLibrary::GetLevelMap()) || ISTRANSIENT) return;
	if (owner->IsA(ACharacter::StaticClass()))
	{
		cell = FCell(owner);
	}
	USingletonLibrary::GetLevelMap()->AddActorOnMapByObj(cell, owner);
}

void UMapComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	owner = GetOwner();
	if (!ISVALID(owner) || !ISVALID(USingletonLibrary::GetLevelMap())|| ISTRANSIENT) return;
	cell = FCell(owner);
	owner->bRunConstructionScriptOnDrag = false;
	//×¢²áÊ±°ó¶¨Î¯ÍÐ
	USingletonLibrary::GetLevelMap()->onActorsUpdatedDelegate.AddDynamic(this, &UMapComponent::UpdateSelfOnMap);
}

void UMapComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (owner != nullptr && ISVALID(USingletonLibrary::GetLevelMap()) && !ISTRANSIENT)
	{
		UE_LOG_STR("OnComponentDestroyed %s", *owner->GetName());
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}
