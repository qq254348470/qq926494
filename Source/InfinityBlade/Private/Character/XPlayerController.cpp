// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "Character/XAnimInstance.h"

//游戏开始调用的方法
void AXPlayerController::BeginPlay()
{
	//设置显示鼠标
	bShowMouseCursor = true;

	//获取默认角色
	XCharacter = Cast<AXCharacter>(GetPawn());
	//获取角色动画实例
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//获得连机动画蒙太奇
	SerialAttackMontage = XCharacter->SerilAttackMontage;
	//获得玩家状态
	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
	//初始化玩家状态
	InitCSPlayerState();
	
	//初始化主界面UI
	MainWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/Main/BP_MainUserWidget.BP_MainUserWidget_c'")));
	//添加到视口
	MainWidget->AddToViewport();
	//判断武器类是否有效
	if (XCharacter->XWeaponClass)
	{
		//生成武器对象
		XWeapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeaponClass);
		//绑定规则
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		//绑定武器
		XWeapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("Weapon_Socket"));
		GEngine->AddOnScreenDebugMessage(-1, 2.5F, FColor::Green, "InitWeapon......");
	}
	InitWidgetEvent();
	if (XAnimInstance)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.5F, FColor::Green, "InitXAniamtion......");
	}

	
}






//绑定输入控件
void  AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//绑定输入
	InputComponent->BindAxis("MoveForward",this,&AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);




}

//void AXPlayerController::Possess(APawn * Pawn)
//{
//	Super::Possess(Pawn);
//	//获取默认角色
//	XCharacter = Cast<AXCharacter>(Pawn);
//	//获取角色动画实例
//	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
//	//获得连机动画蒙太奇
//	SerialAttackMontage = XCharacter->SerilAttackMontage;
//	//获得玩家状态
//	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
//	//初始化玩家状态
//	InitCSPlayerState();
//
//}



//前后移动
void AXPlayerController::MoveForward(float Speed)
{
	//获取控制器的角度
	FRotator Rotation = GetControlRotation();
	//创建偏航角度
	FRotator YawRotation(0.0f,Rotation.Yaw,0.0f);
	//获取移动的方向
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//在该方向添加位移
	XCharacter->AddMovementInput(Direction,Speed);

}

//左右移动
void AXPlayerController::MoveRight(float Speed)
{
	//获取控制器的角度
	FRotator Rotation = GetControlRotation();
	//创建偏航角
	FRotator YawRotation(0.0f,Rotation.Yaw,0.0f);
	//获取移动的方向
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//在该方向添加位移
	XCharacter->AddMovementInput(Direction,Speed);
}

//控件按钮初始化
void AXPlayerController::InitWidgetEvent()
{
	//攻击按钮点击事件绑定
	if (MainWidget->Btn_Attack)
	{
		MainWidget->Btn_Attack->OnClicked.AddDynamic(this,&AXPlayerController::AttackBtnOnClickedEvent);
		GEngine->AddOnScreenDebugMessage(-1, 2.5F, FColor::Green, "InitWidget......");
	}
	
}

//攻击按钮点击事件
void AXPlayerController::AttackBtnOnClickedEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.5F, FColor::Red, "Attack");
	//判断当前蒙太奇是否播放，如果播放则终止；
	if (XAnimInstance->bIsPlaying)
	{
		return;		
	}
	////获得连机动画蒙太奇
	//UAnimMontage* SerialAttackMontage = XCharacter->SerilAttackMontage;
	//获得当前播放的节
	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttackMontage);
	GEngine->AddOnScreenDebugMessage(-1, 13.0f, FColor::Yellow, CurrentSection.ToString());
	//判断
	if (CurrentSection.IsNone())
	{
		//默认播放第一个节
		XAnimInstance->Montage_Play(SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FirstSection")) && XAnimInstance->bIsEnableSecondAttack)
	{
		//播放第二个节
		XAnimInstance->Montage_JumpToSection(FName("SecondSection"),SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("SecondSection")) && XAnimInstance->bIsEnableThirdAttack)
	{
		//播放第三个节
		XAnimInstance->Montage_JumpToSection(FName("ThreeSection"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("ThreeSection")) && XAnimInstance->bIsEnableFourAttack)
	{
		//播放第四个节
		XAnimInstance->Montage_JumpToSection(FName("FourSection"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FourSection")) && XAnimInstance->bIsEnableFiveAttack)
	{
		//播放第五个节
		XAnimInstance->Montage_JumpToSection(FName("FiveSection"), SerialAttackMontage);
	}
	

	
}

void AXPlayerController:: InitCSPlayerState()
{
	//设置当前HP,MP,普通攻击伤害
	XPlayerState->SetCurrentHP(XCharacter->MaxHP);
	XPlayerState->SetCurrentMP(XCharacter->MaxMP);
	XPlayerState->SetAttackDamage(XCharacter->AttackDamage);
}

void AXPlayerController::InitMainUI()
{
}

