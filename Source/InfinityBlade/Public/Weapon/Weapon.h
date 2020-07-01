// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Weapon.generated.h"

//武器类
UCLASS()
class INFINITYBLADE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// 构造方法
	AWeapon();

public:
	//场景组件
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;
	//碰撞体组件
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* CapsuleComponent;
	//武器模型组件
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* WeaponComponent;


	
	
};
