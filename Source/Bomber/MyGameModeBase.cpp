// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Bomber.h"
#include "MyHUD.h"

AMyGameModeBase::AMyGameModeBase()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
	DefaultPawnClass = 0;
	HUDClass = 0;
}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AMyGameModeBase::PossessController(AController* controller, APawn* pawn) const
{
	controller->Possess(pawn);
	Cast<APlayerController>(controller)->SetInputMode(FInputModeGameOnly());
}
