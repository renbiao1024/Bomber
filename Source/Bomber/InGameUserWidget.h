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
	
	//�����ڱ༭����̬����widget
	virtual void SynchronizeProperties() override;

	//BlueprintNativeEvent ��Ҫ�ڶ�����ShowInGameState_Implementation дΪ���ָ�ʽ
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "C++")
	void ShowInGameState(UObject* widget);
};
