// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneratedMap.h"
#include "Components/ActorComponent.h"
#include "MapComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOMBER_API UMapComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMapComponent();

	UFUNCTION(BlueprintCallable, Category = "C++")
	void UpdateSelfOnMap();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	struct FCell cellLocation;

protected:
	virtual void OnComponentCreated() final;

	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) final;
};
