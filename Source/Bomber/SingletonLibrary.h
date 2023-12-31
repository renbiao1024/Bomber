// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Cell.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SingletonLibrary.generated.h"

/*
在项目开发中，我们经常会重复使用某一种功能，如果我们重复使用的功能封装在每个单独的c++类中，
就要去重复去声明实现相同的功能，这样代码重复利用率低并且冗余。
UBlueprintFunctionLibrary是暴露给蓝图的函数库的基类。
这个类提供了一组静态函数，这些函数提供了不依赖于特定游戏对象的实用功能，我们可以在该类中写我们重复利用的功能
 */
UCLASS()
class BOMBER_API USingletonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	USingletonLibrary();

	//BlueprintPure修饰的函数必须有函数返回值或者函数参数输出；否则编译失败
	//通过获得USingletonLibrary这个单例来拿内部的其他单例
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
		//FGenericPlatformMath 通用数学函数库
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
		if (GetLevelMap() == levelMap || levelMap == nullptr || IsValid(USingletonLibrary::GetSingleton()) == false)
			return false;
		GetSingleton()->levelMap_ = levelMap;
		return true;
	}

protected:
	class AGeneratedMap* levelMap_;
};
