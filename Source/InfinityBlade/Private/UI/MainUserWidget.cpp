// Fill out your copyright notice in the Description page of Project Settings.

#include "MainUserWidget.h"


bool UMainUserWidget::Initialize() 
{
	if (!Super::Initialize())
	{
		return false;
	}

	//Setting = Cast<UButton>(GetWidgetFromName("Button_Setting"));
	Btn_Attack = Cast<UButton>(GetWidgetFromName("Button_Attack"));


	return true;

}

