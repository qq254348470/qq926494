// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"



////游戏开始调用的方法
void AStartGameMode::BeginPlay()
{
	//初始化游戏开始界面
	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/Start/BP_StartWidget.BP_StartWidget_c'")));
	StartWidget->AddToViewport();
	//初始化游戏注册界面
	RegisterWidget = CreateWidget<URegisterUserWidget>(GetGameInstance(), LoadClass<URegisterUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/Start/BP_RegisterWidgt.BP_RegisterWidgt_c'")));
	//初始化游戏登陆界面
	LoginWidget = CreateWidget<ULoginUserWidget>(GetGameInstance(), LoadClass<ULoginUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/Start/BP_LoginWidgt.BP_LoginWidgt_c'")));
	//游戏开始界面--登陆按钮点击事件
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AStartGameMode::RegisterBtnOnClickedEvent);
	//游戏开始界面--注册按钮点击事件
	StartWidget->StartBtn->OnClicked.AddDynamic(this, &AStartGameMode::StartBtnOnClickEvent);
	//注册界面--返回按钮点击事件
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this, &AStartGameMode::RegisterBackBtnOnClickedEvent);
	//登陆界面--返回按钮点击事件
	LoginWidget->BackBtn->OnClicked.AddDynamic(this, &AStartGameMode::LoginBackBtnOnClickedEvent);
}

//开始界面--登陆按钮点击事件
void AStartGameMode::StartBtnOnClickEvent()
{
	StartWidget->RemoveFromViewport();
	LoginWidget->AddToViewport();
}

//开始界面--注册按钮点击事件
void AStartGameMode::RegisterBtnOnClickedEvent()
{
	//移除开始界面
	StartWidget->RemoveFromViewport();
	//添加注册界面
	RegisterWidget->AddToViewport();
}
//注册界面--返回按钮点击事件
void AStartGameMode::RegisterBackBtnOnClickedEvent()
{
	//移除注册界面
	RegisterWidget->RemoveFromViewport();
	//添加开始界面
	StartWidget->AddToViewport();
}
//登陆界面--返回按钮点击事件
void AStartGameMode::LoginBackBtnOnClickedEvent()
{
	//移除登陆界面
	LoginWidget->RemoveFromViewport();
	//添加开始界面
	StartWidget->AddToViewport();
}
