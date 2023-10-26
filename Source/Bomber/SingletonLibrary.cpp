// Fill out your copyright notice in the Description page of Project Settings.


#include "SingletonLibrary.h"
#include "Bomber.h"

USingletonLibrary::USingletonLibrary()
{
}

USingletonLibrary* const USingletonLibrary::GetSingleton()
{
	if (!ISVALID(GEngine)) return nullptr;
	USingletonLibrary* singleton = Cast<USingletonLibrary>(GEngine->GameSingleton);
	if (!ISVALID(singleton)) return nullptr;
	return singleton;
}

