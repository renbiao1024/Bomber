// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Bomber.h"
#include "InGameUserWidget.h"

AMyHUD::AMyHUD()
{
	//widget ����
	TSubclassOf<UUserWidget> umgMenuClass, umgHudClass, umgCurrentClass;

	//�ҵ���Ӧ��widget
	static ConstructorHelpers::FClassFinder<UUserWidget> umgMenuFinder(TEXT("/Game/Bomber/UI/UI_Menu"));
	if (umgMenuFinder.Succeeded())
	{
		umgMenuClass = umgMenuFinder.Class;
	}
	static ConstructorHelpers::FClassFinder<UUserWidget> umgHUDFinder(TEXT("/Game/Bomber/UI/UI_HUD"));
	if (umgHUDFinder.Succeeded())
	{
		umgHudClass = umgHUDFinder.Class;
	}

	umgCurrentClass = (UGameplayStatics::GetCurrentLevelName(GetWorld()) == "MenuLevel" ? umgMenuClass : umgHudClass);
	umgCurrentObj = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), umgCurrentClass);
}

void AMyHUD::BeginPlay()
{
	if (IsValid(umgCurrentObj))
		umgCurrentObj->AddToViewport();
}
