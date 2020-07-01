// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Weapon.generated.h"

//������
UCLASS()
class INFINITYBLADE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// ���췽��
	AWeapon();

public:
	//�������
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;
	//��ײ�����
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* CapsuleComponent;
	//����ģ�����
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* WeaponComponent;


	
	
};
