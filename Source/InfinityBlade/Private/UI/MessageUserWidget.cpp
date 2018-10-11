// Fill out your copyright notice in the Description page of Project Settings.

#include "MessageUserWidget.h"



//控件创建初始化
bool UMessageUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	MsgBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Msg")));
	CloseBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Close")));
	CloseBtn->OnClicked.AddDynamic(this, &UMessageUserWidget::CloseBtnOnClickedEvent);



	return true;
}

//关闭按钮点击事件
void UMessageUserWidget::CloseBtnOnClickedEvent()
{
	SetVisibility(ESlateVisibility::Hidden);
}

//提示框更新事件
void UMessageUserWidget::ShowTipEvent(FString Tip)
{
	SetVisibility(ESlateVisibility::Visible);
	MsgBlock->SetText(FText::FromString(Tip));
}
