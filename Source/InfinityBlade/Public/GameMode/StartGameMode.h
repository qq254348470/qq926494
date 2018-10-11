// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "StartUserWidget.h"
#include "RegisterUserWidget.h"
#include "LoginUserWidget.h"
#include "StartGameMode.generated.h"


/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	//游戏开始调用的方法
	virtual void BeginPlay() override;

public:
	//游戏开始界面
	UPROPERTY()
		UStartUserWidget* StartWidget;
	//游戏注册界面
	UPROPERTY()
		URegisterUserWidget* RegisterWidget;
	//游戏登陆界面
	UPROPERTY()
		ULoginUserWidget* LoginWidget;
	

public:
	//开始界面--开始按钮点击事件
	UFUNCTION()
		void StartBtnOnClickEvent();
	//开始界面--注册按钮点击事件
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	//注册界面--返回按钮点击事件
	UFUNCTION()
		void RegisterBackBtnOnClickedEvent();
	//登陆界面--返回按钮点击事件
	UFUNCTION()
		void LoginBackBtnOnClickedEvent();


};
