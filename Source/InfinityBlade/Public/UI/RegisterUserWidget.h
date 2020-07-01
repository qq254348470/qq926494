// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "MessageUserWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/CircularThrobber.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "CustomGameInstance.h"
#include "RegisterUserWidget.generated.h"

/**
 * 游戏注册界面UI
 */
UCLASS()
class INFINITYBLADE_API URegisterUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//返回按钮
	UPROPERTY()
		UButton* BackBtn;
	//注册按钮
	UPROPERTY()
		UButton* RegisterBtn;
	//账号输入框
	UPROPERTY()
		UEditableTextBox* NicknameInput;
	//密码输入框
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	//重复密码输入框
	UPROPERTY()
		UEditableTextBox* RePasswordInput;
	//环形进度条
	UPROPERTY()
		UCircularThrobber* CircularThrobber;
	//信息提示框
	UPROPERTY()
		UMessageUserWidget* MessageWidget;
	

public: 
	//控件初始化方法
	virtual bool Initialize() override;
	//注册界面--注册按钮点击事件
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	//注册界面--账号注册方法
	void AccountRegisterFromServer(FString& Nickname, FString& Password);
	//请求响应方式
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);



};
