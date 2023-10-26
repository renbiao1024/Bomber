// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "MapComponent.h"
#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "SingletonLibrary.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

#define UE_LOG_STR(message, string) UE_LOG(LogTemp, Warning, TEXT(message), string)
#define ISVALID(obj) ((obj != nullptr) && IsValid(obj) && !obj->IsPendingKill() && obj->IsValidLowLevel())
#define ISTRANSIENT(obj) (obj->HasAllFlags(RF_Transient) || UGameplayStatics::GetCurrentLevelName(obj->GetWorld()) == "Transient")