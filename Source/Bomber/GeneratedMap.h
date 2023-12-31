// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Cell.h"
#include "GameFramework/Actor.h"
#include "GeneratedMap.generated.h"

UENUM(BlueprintType, meta = (Bitflags))
enum class EPathTypesEnum : uint8  //地图类型
{
	Default = 0,
	Explosion = 1 << 0,
	Free = 1 << 1,
	Safe = 1 << 2,
	Secure = 1 << 3,
};

UENUM(BlueprintType, meta = (Bitflags))
enum class EActorTypeEnum : uint8 //地图物品类型
{
	Default = 0,
	Wall = 1 << 0,
	Box = 1 << 1,
	Bomb = 1 << 2,
	Item = 1 << 3,
	Floor = 1 << 4,
	Player = 1 << 5,
};

UCLASS()
class BOMBER_API AGeneratedMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneratedMap();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPushNongeneratedToMap);
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "C++")
	FPushNongeneratedToMap onActorsUpdatedDelegate;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "C++")
	TSet<FCell> GetSidesCells(const FCell& cell, int32 sideLength, EPathTypesEnum pathfinder) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "C++", meta = (AdvancedDisplay = 2))
	TSet<FCell> FilterCellsByTypes(const TSet<FCell>& keys, TArray<EActorTypeEnum>& filterTypes, const class ACharacter* excludePlayer) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++")
	AActor* AddActorOnMap(const FCell& cell, EActorTypeEnum actorType);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++")
	void AddActorOnMapByObj(const FCell& cell, const AActor* updateActor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++")
	void DestroyActorsFromMap(const FCell& cell);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	TSet<const class ACharacter*> charactersOnMap_;

protected:
	friend struct FCell;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Destroyed() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++")
	void GenerateLevelMap();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++", meta = (DisplayName = "Grid Array"))
	TMap<FCell, const AActor*> GeneratedMap_;

	//只能在蓝图中实现，而不能在C++中实现
	UFUNCTION(BlueprintImplementableEvent, Category = "C++", meta = (DevelopmentOnly))
	FCell GetNearestCell(const AActor* actor);
};
