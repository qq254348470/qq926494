// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "TextBlock.h"
#include "MessageUserWidget.generated.h"

/**
 * 信息提示框UI
 */
UCLASS()
class INFINITYBLADE_API UMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//关闭按钮
	UPROPERTY()
		UButton* CloseBtn;
	//提示框
	UPROPERTY()
		UTextBlock* MsgBlock;

public:
	//控件创建初始化
	virtual bool Initialize() override;
	//关闭按钮点击事件
	UFUNCTION()
		void CloseBtnOnClickedEvent();
	//提示框更新事件
	UFUNCTION()
		void ShowTipEvent(FString Tip);
	
	
};
