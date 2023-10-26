// Fill out your copyright notice in the Description page of Project Settings.


#include "SingletonLibrary.h"
#include "Bomber.h"

USingletonLibrary::USingletonLibrary()
{
	TArray<TCHAR*> pathes
	{
		TEXT("/Game/Bomber/BP/BPBomb.BPBomb"),
		TEXT("/Game/Bomber/BP/BPBomb.BPBox"),
		TEXT("/Game/Bomber/BP/BPBomb.BPCameraActor"),
		TEXT("/Game/Bomber/BP/BPBomb.BPFloor"),
		TEXT("/Game/Bomber/BP/BPBomb.BPItem"),
		TEXT("/Game/Bomber/BP/BPBomb.BPPlayer"),
		TEXT("/Game/Bomber/BP/BPBomb.BPWall"),
	};

	for (auto path : pathes)
	{
		ConstructorHelpers::FClassFinder<AActor> classFinder(path);
		bpClasses.Add(classFinder.Class);
	}
}

USingletonLibrary* const USingletonLibrary::GetSingleton()
{
	if (!ISVALID(GEngine)) return nullptr;
	USingletonLibrary* singleton = Cast<USingletonLibrary>(GEngine->GameSingleton);
	if (!ISVALID(singleton)) return nullptr;
	return singleton;
}

