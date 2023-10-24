// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "InGameUserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class BOMBER_API UInGameUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;
	
	//用于在编辑器动态更新widget
	virtual void SynchronizeProperties() override;

	//BlueprintNativeEvent 需要在定义中ShowInGameState_Implementation 写为这种格式
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "C++")
	void ShowInGameState(UObject* widget);
};
