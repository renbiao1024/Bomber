// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

USTRUCT(BlueprintType)
struct FPowerUp
{
	GENERATED_BODY()

public:
	FPowerUp() {};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	int skateN = 1; //加速
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	int bombN = 1;	 //炸弹数量
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	int fireN = 1;  //爆炸范围
};

UCLASS()
class BOMBER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION(BlueprintCallable, Category = "C++")
	void SpawnBomb();

	UPROPERTY(BlueprintReadOnly, Category = "C++")
	class UMapComponent* mapComponent_;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	FPowerUp powerups_;
	
	friend class AItem;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "C++")
	int32 characterID_;
};
