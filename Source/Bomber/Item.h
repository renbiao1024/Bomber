// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class BOMBER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(BlueprintReadOnly, Category = "C++")
	class UMapComponent* mapComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION()
	void OnItemBeginOverlap(AActor* overlappedItem, AActor* otherActor);

	UPROPERTY()
	class UMapComponent* mapComponent_;
};
