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
	//��ͨ�����˺�
	float AttackDamege;
	//��ǰѪ��
	float CurrentHP;
	//��ǰħ��ֵ
	float CurrentMP;

public:
	//��---������ͨ�����˺�
	FORCEINLINE float GetAttackDamage() { return AttackDamege; }
	//���ù����˺�
	FORCEINLINE void SetAttackDamage(float AttackDamage) { this->AttackDamege = AttackDamege; }
	//��ȡ��ǰѪ��
	FORCEINLINE float GetCurrentAttack() { return CurrentHP; };
	//���õ�ǰѪ��
	FORCEINLINE void SetCurrentHP(float CurrentHP) { this->CurrentHP; }
	//��ȡ��ǰħ��ֵ
	FORCEINLINE float GetCurrentMP() { return CurrentMP; }
	//���õ�ǰħ��ֵ
	FORCEINLINE void SetCurrentMP(float CurrentMP) { this->CurrentMP = CurrentMP; };

	
	
	
};
