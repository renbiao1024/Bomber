// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOMBER_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();

	void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "C++")
	class UUserWidget* umgCurrentObj;
};
