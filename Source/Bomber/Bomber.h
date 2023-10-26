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

#define UE_LOG_STR(message, string) UE_LOG(LogTemp, Warning, TEXT(message), string)
#define ISVALID(obj) ((obj != nullptr) && IsValid(obj) && (obj->IsPendingKill() == false))
#define ISTRANSIENT (HasAllFlags(RF_Transient) || UGameplayStatics::GetCurrentLevelName(GetWorld()) == "Transient")