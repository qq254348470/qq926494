// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "XPlayerController.h"
#include "XPlayerState.h"

void AMainGameMode::BeginPlay()
{
	
	
		


}

//构造方法
AMainGameMode::AMainGameMode()
{
	//静态加载，找到资源蓝图类Blueprint'/Game/Character/BP_XCharacter.BP_XCharacter_c
	ConstructorHelpers::FClassFinder<ACharacter> CharacterFinder(TEXT("Blueprint'/Game/Character/CSXCharacter.CSXCharacter_c'"));
	//设置默认角色
	DefaultPawnClass = CharacterFinder.Class;
	//设置默认角色控制器
	PlayerControllerClass = AXPlayerController::StaticClass();
	//设置PlayerState
	PlayerStateClass = AXPlayerState::StaticClass();

}