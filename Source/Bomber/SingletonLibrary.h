// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SingletonLibrary.generated.h"

/*
����Ŀ�����У����Ǿ������ظ�ʹ��ĳһ�ֹ��ܣ���������ظ�ʹ�õĹ��ܷ�װ��ÿ��������c++���У�
��Ҫȥ�ظ�ȥ����ʵ����ͬ�Ĺ��ܣ����������ظ������ʵͲ������ࡣ
UBlueprintFunctionLibrary�Ǳ�¶����ͼ�ĺ�����Ļ��ࡣ
������ṩ��һ�龲̬��������Щ�����ṩ�˲��������ض���Ϸ�����ʵ�ù��ܣ����ǿ����ڸ�����д�����ظ����õĹ���
 */
UCLASS()
class BOMBER_API USingletonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	USingletonLibrary();

	//BlueprintPure���εĺ��������к�������ֵ���ߺ�������������������ʧ��
	//ͨ�����USingletonLibrary������������ڲ�����������
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "C++")
	static USingletonLibrary* const GetSingleton();

	UPROPERTY(BlueprintReadWrite)
	class AGeneratedMap* levelMap;
};
