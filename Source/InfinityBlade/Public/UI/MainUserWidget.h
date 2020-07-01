// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainUserWidget.generated.h"


/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
	
	public:
		virtual bool Initialize() override;

	public:
		//第二种按钮绑定方式
		//攻击按钮
		//UPROPERTY(Meta = (BindWidget))
		UPROPERTY()
			UButton* Btn_Attack;

};
