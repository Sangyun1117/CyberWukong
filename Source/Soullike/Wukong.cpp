// Fill out your copyright notice in the Description page of Project Settings.


#include "Wukong.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputMappingContext.h"
#include "InputAction.h"

// Sets default values
AWukong::AWukong()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWukong::BeginPlay()
{
	Super::BeginPlay();
	
	// PlayerController를 통해 접근
	//if (APlayerController* PC = Cast<APlayerController>(Controller))
	//{
	//	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
	//	{
	//		Subsystem->AddMappingContext(InputMappingContext, 0);
	//	}
	//}
}
// Called every frame
void AWukong::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWukong::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	//{
	//	Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AWukong::OnHitMove);
	//	Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AWukong::OnHitLook);
	//	Input->BindAction(IA_Roll, ETriggerEvent::Triggered, this, &AWukong::OnHitRoll);
	//}
}

//void AWukong::OnHitMove(const FInputActionValue& Value)
//{
//}
//
//void AWukong::OnHitLook(const FInputActionValue& Value)
//{
//}
//
//void AWukong::OnHitRoll(const FInputActionValue& Value)
//{
//}

