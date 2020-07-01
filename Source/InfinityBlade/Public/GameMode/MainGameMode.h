// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/Character.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "MainGameMode.generated.h"

/**
 * 主关卡游戏模式
 */
UCLASS()
class INFINITYBLADE_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
		

	public:
		//游戏开始调用的方法
		virtual void BeginPlay() override;
		AMainGameMode();

	
	
};
