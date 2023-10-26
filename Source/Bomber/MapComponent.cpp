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
	if (!ISVALID(GetOwner()) || !ISVALID(USingletonLibrary::GetLevelMap()) || ISTRANSIENT) return;
	cellLocation = FCell(GetOwner());
	//���ݸ������ӵ������Ϣ���MapComponent
	USingletonLibrary::GetLevelMap()->AddActorOnMapByObj(GetOwner());
}

void UMapComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	if (!ISVALID(GetOwner()) || !ISVALID(USingletonLibrary::GetLevelMap())|| ISTRANSIENT) return;
	GetOwner()->bRunConstructionScriptOnDrag = false;
	//ע��ʱ��ί��
	USingletonLibrary::GetLevelMap()->onActorsUpdateDelegate.AddDynamic(this, &UMapComponent::UpdateSelfOnMap);
}

void UMapComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	if (!ISVALID(USingletonLibrary::GetLevelMap()) || ISTRANSIENT) return;

	USingletonLibrary::GetLevelMap()->DestroyActorFromMap(cellLocation);
}
