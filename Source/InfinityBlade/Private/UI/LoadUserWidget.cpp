// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadUserWidget.h"



//初始化开始调用的方法
bool ULoadUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//初始化加载UI
	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName("Loading"));
	//初始化提示文字
	LoadingText = Cast<UTextBlock>(GetWidgetFromName("TextTip"));


	return true;
}


//加载完成更新UI事件
void ULoadUserWidget::HiddenLoading()
{
	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	LoadingText->SetText(FText::FromString(L"点击继续..."));

}
