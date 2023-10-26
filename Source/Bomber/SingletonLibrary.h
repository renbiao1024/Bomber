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
	static const FORCEINLINE FCell MakeCell(const AActor* actor)
	{
		return FCell(actor);
	}

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "C++", meta = (DisplayName = "Get Grid Size"))
	static const FORCEINLINE float GetFloorLength()
	{
		return 200.0;
	}

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "C++")
	static const FORCEINLINE float CalculateCellsLength(const FCell& x, const FCell& y)
	{
		//FGenericPlatformMath ͨ����ѧ������
		return (fabs((x.location - y.location).Size()) / GetFloorLength());
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "C++")
	static FORCEINLINE class AGeneratedMap* const GetLevelMap()
	{
		return (IsValid(GetSingleton()) ? GetSingleton()->levelMap_ : nullptr);
	}

	UFUNCTION(BlueprintCallable, Category = "C++")
	static FORCEINLINE bool SetLevelMap(class AGeneratedMap* levelMap)
	{
		if (GetLevelMap() == levelMap || IsValid(levelMap) == false || IsValid(USingletonLibrary::GetSingleton()) == false)
			return false;
		GetSingleton()->levelMap_ = levelMap;
		return true;
	}

	UPROPERTY(BlueprintReadOnly, Category = "C++", meta = (BlueprintBaseOnly))
	TArray<const TSubclassOf<AActor>> bpClasses;

protected:
	class AGeneratedMap* levelMap_;
};
