// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "TextBlock.h"
#include "MessageUserWidget.generated.h"

/**
 * ��Ϣ��ʾ��UI
 */
UCLASS()
class INFINITYBLADE_API UMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//�رհ�ť
	UPROPERTY()
		UButton* CloseBtn;
	//��ʾ��
	UPROPERTY()
		UTextBlock* MsgBlock;

public:
	//�ؼ�������ʼ��
	virtual bool Initialize() override;
	//�رհ�ť����¼�
	UFUNCTION()
		void CloseBtnOnClickedEvent();
	//��ʾ������¼�
	UFUNCTION()
		void ShowTipEvent(FString Tip);
	
	
};
