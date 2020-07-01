// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AXPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	//普通攻击伤害
	float AttackDamege;
	//当前血量
	float CurrentHP;
	//当前魔法值
	float CurrentMP;

public:
	//宏---返回普通攻击伤害
	FORCEINLINE float GetAttackDamage() { return AttackDamege; }
	//设置攻击伤害
	FORCEINLINE void SetAttackDamage(float AttackDamage) { this->AttackDamege = AttackDamege; }
	//获取当前血量
	FORCEINLINE float GetCurrentAttack() { return CurrentHP; };
	//设置当前血量
	FORCEINLINE void SetCurrentHP(float CurrentHP) { this->CurrentHP; }
	//获取当前魔法值
	FORCEINLINE float GetCurrentMP() { return CurrentMP; }
	//设置当前魔法值
	FORCEINLINE void SetCurrentMP(float CurrentMP) { this->CurrentMP = CurrentMP; };

	
	
	
};
