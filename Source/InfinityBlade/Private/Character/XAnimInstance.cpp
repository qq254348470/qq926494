// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"

//更新人物移动速度
void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner()!=nullptr)
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

//开始播放蒙太奇
void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify * Notify)
{
	bIsPlaying = true;
}

//结束播放蒙太奇
void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify * Notify)
{
	bIsPlaying = false;
}

void UXAnimInstance::AnimNotify_ResetSerialAttack(UAnimNotify * Notify)
{
	bIsEnableSecondAttack = false;
	bIsEnableThirdAttack = false;
	bIsEnableFourAttack = false;
	bIsEnableFiveAttack = false;

}

void UXAnimInstance::AnimNotify_SecondAttackInput(UAnimNotify * Notify)
{
	bIsEnableSecondAttack = true;
}

void UXAnimInstance::AnimNotify_ThirdAttackInput(UAnimNotify * Notify)
{
	bIsEnableThirdAttack = true;
}

void UXAnimInstance::AnimNotify_FourAttackInput(UAnimNotify * Notify)
{
	bIsEnableFourAttack = true;
}

void UXAnimInstance::AnimNotify_FiveAttackInput(UAnimNotify * Notify)
{
	bIsEnableFiveAttack = true;
}
