// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CircularThrobber.h"
#include "TextBlock.h"
#include "LoadUserWidget.generated.h"

/**
 * 加载UI
 */
UCLASS()
class INFINITYBLADE_API ULoadUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
		
public:
	//加载进度条
	UPROPERTY()
		UCircularThrobber* CircularThrobber;
	//加载提示
	UPROPERTY()
		UTextBlock* LoadingText;
	

public:
	//初始化开始调用的方法
	virtual bool Initialize() override;
	//加载完成更新UI事件
	UFUNCTION()
		void HiddenLoading();

	
};
