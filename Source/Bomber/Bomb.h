// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBER_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	void InitializeBombProperties(int32* outBombN, const int32& fireN, const int32& characterID);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class UStaticMeshComponent* bombMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Destroyed() override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UPROPERTY()
	class UMapComponent* mapComponent_;

	UPROPERTY(EditAnywhere, Category = "C++")
	float lifeSpan_ = 2.f;

	UPROPERTY(EditAnywhere, Category = "C++", meta = (DisplayName = "Explosion Length"))
	int32 characterFireN_ = 1;

	int32* characterBombN_;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	TArray<class UMaterialInterface*>bombMaterials_;

	friend class AGeneratedMap;
};
