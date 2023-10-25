// Fill out your copyright notice in the Description page of Project Settings.


#include "SingletonLibrary.h"

USingletonLibrary::USingletonLibrary()
{
}

USingletonLibrary* const USingletonLibrary::GetSingleton()
{
	if (IsValid(GEngine) == false) return nullptr;
	USingletonLibrary* singleton = Cast<USingletonLibrary>(GEngine->GameSingleton);
	if (IsValid(singleton) == false) return nullptr;
	return singleton;
}
