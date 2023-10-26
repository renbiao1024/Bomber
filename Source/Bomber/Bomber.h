// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "GeneratedMap.h"
#include "SingletonLibrary.h"
#include "MapComponent.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"

#define PRINT(string) GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, string, true. FVector2D(2,2));
#define ISVALID(obj) ((obj != nullptr) && IsValid(obj) && !obj->IsPendingKill())
#define ISTRANSIENT (HasAllFlags(RF_Transient) || UGameplayStatics::GetCurrentLevelName(GetWorld()) == "Transient")