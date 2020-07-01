// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Weapon.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/SpringArmComponent.h"
#include "XCharacter.generated.h"



//英雄角色类
UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	//摄像机组件
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
		UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arm")
		USpringArmComponent* SpringArm;
	//武器类
	UPROPERTY(EditAnywhere,Category = "Weapon")
		TSubclassOf<AWeapon> XWeaponClass;
	
public:
	//连击蒙太奇动画
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SerilAttackMontage; 
	//总血量
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float MaxHP;
	//总魔法值
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float MaxMP;
	//普通攻击伤害
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float AttackDamage;

public:
	// 构造方法   Sets default values for this character's properties
	AXCharacter();

protected:
	//游戏开始调用的方法   Called when the game starts or when spawned
	virtual void BeginPlay()  override;


	
	
};
