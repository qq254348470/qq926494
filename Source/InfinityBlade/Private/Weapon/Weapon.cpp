// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"


// ���췽��
AWeapon::AWeapon()
{
	//��ʼ���������
	//SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	//��ʼ������ģ�����
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponComponent");	
	//��ʼ����ײ�����
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	//��������ģ�͸����
	WeaponComponent->SetupAttachment(RootComponent);
	//��������ģ����ײ�����
	CapsuleComponent->SetupAttachment(WeaponComponent);
	

}


