// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOMBER_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

	void BeginPlay() override;

	void SetupInputComponent() override;

	DECLARE_DELEGATE_OneParam(FEscapeDelegate, UObject*);

	UPROPERTY(BlueprintReadOnly, Category = "C++")
	class AMyHUD* MyCustomHUD;
};
