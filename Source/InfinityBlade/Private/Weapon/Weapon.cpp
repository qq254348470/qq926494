// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"


// 构造方法
AWeapon::AWeapon()
{
	//初始化场景组件
	//SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	//初始化武器模型组件
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponComponent");	
	//初始化碰撞体组件
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	//设置武器模型父组件
	WeaponComponent->SetupAttachment(RootComponent);
	//设置武器模型碰撞体组件
	CapsuleComponent->SetupAttachment(WeaponComponent);
	

}


