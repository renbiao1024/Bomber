// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Bomber.h"
#include "InGameUserWidget.h"
#include "MyHUD.h"

AMyPlayerController::AMyPlayerController()
{
	bAutoManageActiveCameraTarget = false;
}

void AMyPlayerController::BeginPlay()
{
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	MyCustomHUD = GetWorld()->SpawnActor<AMyHUD>(AMyHUD::StaticClass());
	InputComponent->BindAction("EscapeEvent", IE_Pressed, Cast<UInGameUserWidget>(MyCustomHUD->umgCurrentObj),
		&UInGameUserWidget::ShowInGameState);
}

