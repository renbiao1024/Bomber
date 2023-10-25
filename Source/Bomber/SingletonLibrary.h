// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneratedMap.h"
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

	UFUNCTION(BlueprintPure, Category = "C++", meta = (CompactNodeTitle = "toCell"))
	static FORCEINLINE FCell MakeCell(const FVector& cellLocation)
	{
		return FCell(cellLocation);
	}

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "C++")
	static FORCEINLINE float GetFloorLength()
	{
		return 200.0;
	}

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "C++")
	static FORCEINLINE float CalculateCellsLength(const FCell& x, const FCell& y)
	{
		//FGenericPlatformMath ͨ����ѧ������
		return (fabs((x.location - y.location).Size()) / GetFloorLength());
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "C++")
	static FORCEINLINE class AGeneratedMap* const GetLevelMap()
	{
		return GetSingleton()->levelMap;
	}

	class AGeneratedMap* levelMap;

	UPROPERTY(BlueprintReadWrite, Category = "C++", meta = (BlueprintBaseOnly))
	TArray<TSubclassOf<AActor>> bpClasses;
};
