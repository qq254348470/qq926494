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
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"
#include "LoginUserWidget.generated.h"

/**
 * 登陆界面
 */
UCLASS()
class INFINITYBLADE_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	//返回按钮
	UPROPERTY()
		UButton* BackBtn;
	//登陆按钮
	UPROPERTY()
		UButton* LoginBtn;
	//账号输入框
	UPROPERTY()
		UEditableTextBox* NicknameInput;
	//密码输入框
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	//信息提示框
	UPROPERTY()
		UMessageUserWidget* MessageWidget;
	UPROPERTY()
		UCircularThrobber* CircularThrobber;

 
public:
	
	//控件创建完成后初始化方法
	virtual bool Initialize() override;
	//登录按钮点击事件
	UFUNCTION()
		void LoginBtnOnClickedEvent();
	//注册界面--账号注册方法
	void AccountRegisterFromServer(FString& Nickname, FString& Password);
	//请求响应方式
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);

};
