// Fill out your copyright notice in the Description page of Project Settings.


#include "Wukong.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "DamageReceiver.h"
#include "Blueprint/UserWidget.h"

AWukong::AWukong()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWukong::BeginPlay()
{
	Super::BeginPlay();
	
	// PlayerController를 통해 접근
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}

	if (DamageReceiver) {
		DamageReceiver->SetHp(MaxHp);
	}
}

void AWukong::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWukong::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AWukong::OnHitMove);
		Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AWukong::OnHitLook);
		Input->BindAction(IA_Roll, ETriggerEvent::Triggered, this, &AWukong::OnHitRoll);
	}
}

//사용자 키입력
void AWukong::OnHitMove(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Move"));
}

void AWukong::OnHitLook(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Look"));
}

void AWukong::OnHitRoll(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Roll"));
}


//void AWukong::OnHpChanged(float CurrentHp, float MaxHp)
//{
//}
//
//void AWukong::OnDead()
//{
//}

