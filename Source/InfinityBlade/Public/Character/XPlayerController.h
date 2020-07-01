// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XCharacter.h"
#include "MainUserWidget.h"
#include "XPlayerState.h"
#include "XPlayerController.generated.h"

/**
 * 玩家控制器 
 */

class UXAnimInstance;
class UAnimMontage;

UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	//游戏开始调用的方法
	virtual void BeginPlay() override;
	//绑定输入控件
	virtual void SetupInputComponent() override;
	//重写绑定角色函数
	//virtual void Possess(APawn* Pawn)override;
	

public:
	//前后移动
	UFUNCTION()
		void MoveForward(float Spped);
	//左右移动
	UFUNCTION()
	    void MoveRight(float Speed);
	
public:
	//获取控制角色
	UPROPERTY()
		AXCharacter* XCharacter;
	//角色动画实例
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	//角色蒙太奇
	UPROPERTY()
		UAnimMontage* SerialAttackMontage;
	//主界面UI
	UPROPERTY()
		UMainUserWidget* MainWidget;
	//武器对象
	UPROPERTY()
		AWeapon* XWeapon;
	//玩家状态
	UPROPERTY()
		AXPlayerState* XPlayerState;
	

public:
	//控件按钮初始化
	void InitWidgetEvent();
	//攻击按钮点击事件
	UFUNCTION()
		void AttackBtnOnClickedEvent();
	//初始化玩家状态
	void InitCSPlayerState();
	//初始化UI
	void InitMainUI();

};
