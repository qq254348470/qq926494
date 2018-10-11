// Fill out your copyright notice in the Description page of Project Settings.

#include "MessageUserWidget.h"



//�ؼ�������ʼ��
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

//�رհ�ť����¼�
void UMessageUserWidget::CloseBtnOnClickedEvent()
{
	SetVisibility(ESlateVisibility::Hidden);
}

//��ʾ������¼�
void UMessageUserWidget::ShowTipEvent(FString Tip)
{
	SetVisibility(ESlateVisibility::Visible);
	MsgBlock->SetText(FText::FromString(Tip));
}
