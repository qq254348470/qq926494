// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	//开始加载地图的委托
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	//结束加载地图的委托
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
	//初始化加载UI
	LoadWidget = CreateWidget<ULoadUserWidget>(this,LoadClass<ULoadUserWidget>(this,TEXT("WidgetBlueprint'/Game/UI/BP_LoadWidget.BP_LoadWidget_c'")));

}

//地图加载开始的方法
void UCustomGameInstance::PreLoadMap(const FString& Map)
{
	//判断是否是加载的主关卡
	if(Map.Equals("/Game/Map/Map_Main"))
	{
		//创建一个屏幕加载属性对象
		FLoadingScreenAttributes LoadingAttr;
		//手动点击跳过加载
		LoadingAttr.bWaitForManualStop = true;
		//设置加载的Widget
		LoadingAttr.WidgetLoadingScreen = LoadWidget->TakeWidget();
		//设置加载屏幕
		GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);
	}

}

//地图加载结束的方法（秒切换，不行）
void UCustomGameInstance::PostLoadMap(UWorld* World)
{
	//LoadWidget->HiddenLoading();
}

//地图是否加载完成
bool UCustomGameInstance::GetLoadStatus()
{	
	return 	GetMoviePlayer()->IsLoadingFinished();

}

void UCustomGameInstance::UpdateTip() 
{
	LoadWidget->HiddenLoading();

}