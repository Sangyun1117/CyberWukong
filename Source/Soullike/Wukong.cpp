// Fill out your copyright notice in the Description page of Project Settings.


#include "Wukong.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "DamageReceiver.h"
#include "Blueprint/UserWidget.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerHUD.h"

AWukong::AWukong()
{
	PrimaryActorTick.bCanEverTick = true;
	WukongState = EPlayerState::Peace;
	DamageReceiver = CreateDefaultSubobject<UDamageReceiver>(TEXT("DamageReceiver"));

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
		DamageReceiver->OnDead.AddDynamic(this, &AWukong::OnDead);
		DamageReceiver->OnHealthPowerChanged.AddDynamic(this, &AWukong::OnHpChanged);
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
		Input->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AWukong::OnHitJump);
		Input->BindAction(IA_Roll, ETriggerEvent::Triggered, this, &AWukong::OnHitRollInput);
		Input->BindAction(IA_Attack, ETriggerEvent::Triggered, this, &AWukong::OnHitAttack);
	}
}

//사용자 키입력
void AWukong::OnHitMove(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Move"));
	if (!bCanMove || WukongState != EPlayerState::Peace) {
		return;
	}

	FVector2D MoveAxisVector = Value.Get<FVector2D>();

	//컨트롤러 회전값. 카메라가 플레이어 위에서 찍으면 캐릭터가 안움직이는 문제해결을 위해 요회전만 사용
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	//매시 -90도 회전되있음
	AddMovementInput(ForwardDirection, MoveAxisVector.X);
	AddMovementInput(RightDirection, MoveAxisVector.Y);
}

//카메라 이동
void AWukong::OnHitLook(const FInputActionValue& Value)
{
	//UE_LOG(LogTemp, Log, TEXT("Look: %f, %f"), X, Y);
	// FInputActionValue를 FVector2D로 변환
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);

}

void AWukong::OnHitJump(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Jump"));
	if (!bCanMove) {
		return;
	}
	Jump();
}

void AWukong::OnHitRollInput(const FInputActionValue& Value)
{
	OnHitRoll(Value);
}

bool AWukong::OnHitRoll_Implementation(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Roll"));
	if (WukongState != EPlayerState::Peace || GetCharacterMovement()->IsFalling()) {
		return false;
	}
	switch (AttackState)
	{
	case EAttackState::Hit:
	case EAttackState::SlamPush:
	case EAttackState::SlamDown:
		return false;
	case EAttackState::None:
		NextCombo = NAME_None;
		break;
	}

	SetState(EPlayerState::Roll);
	return true;
}

void AWukong::OnHitAttack(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Attack"));

}



void AWukong::OnHpChanged(float HealthPower, float MaxHealthPower) {
	UE_LOG(LogTemp, Log, TEXT("HpChanged"));
	CurrentHp = HealthPower;
	MaxHp = MaxHealthPower;
	PlayerHUD->SetHp(CurrentHp, MaxHp);
}

//데미지리시버에서 알려줌
void AWukong::OnDead()
{
	UE_LOG(LogTemp, Log, TEXT("Dead"));

	//죽는 모션중 공격 무시
	ECollisionChannel MonsterAttackChannel = ECC_GameTraceChannel4;
	GetCapsuleComponent()->SetCollisionResponseToChannel(MonsterAttackChannel, ECR_Ignore);

	//상태 변경
	SetState(EPlayerState::Dead);
}

void AWukong::SetState(EPlayerState NewState)
{
	UE_LOG(LogTemp, Log, TEXT("SetState"));
	if (WukongState != EPlayerState::Dead) {
		WukongState = NewState;
	}
}

