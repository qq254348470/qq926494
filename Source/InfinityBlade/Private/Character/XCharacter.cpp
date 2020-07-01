// Fill out your copyright notice in the Description page of Project Settings.

#include "XCharacter.h"


//构造方法 Sets default values
AXCharacter::AXCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//设置角色移动的朝向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//设置角色控制器是否控制朝向
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//初始化相机组件
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");

	CameraComponent->bUsePawnControlRotation = false;
	//相机角色控制器控制朝向
	CameraComponent->bUsePawnControlRotation = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = false;
	//相机组件绑定父组件
	CameraComponent->SetupAttachment(SpringArm);
	SpringArm->RelativeRotation = FRotator(-25.0f,0.0f,0.0f);


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	


}

// 游戏开始调用的方法  Called when the game starts or when spawned
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


