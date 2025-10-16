// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "GameEnums.h"
#include "Wukong.generated.h"

class UDamageReceiver;
class UUserWidget;
class USphereComponent;
class UCapsuleComponent;
class UPlayerHUD;
UCLASS()
class SOULLIKE_API AWukong : public ACharacter
{
	GENERATED_BODY()

public:
	AWukong();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	//사용자 키입력
	void OnHitMove(const FInputActionValue& Value);
	void OnHitLook(const FInputActionValue& Value);
	void OnHitJump(const FInputActionValue& Value);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Input")
	bool OnHitRoll(const FInputActionValue& Value);
	bool OnHitRoll_Implementation(const FInputActionValue& Value);
	void OnHitAttack(const FInputActionValue& Value);


private:

	UFUNCTION()
	void OnHpChanged(float HealthPower, float MaxHealthPower);

	UFUNCTION()
	void OnDead();

	UFUNCTION(BlueprintCallable)
	void SetState(EPlayerState NewState);

	//반환형이 void가 아니면 BindAction을 못하므로 사용하는 래퍼함수
	void OnHitRollInput(const FInputActionValue& Value);

protected:
	//입력 매핑 변수
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Look;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Jump;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Attack;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Slam;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Roll;

	//컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UDamageReceiver* DamageReceiver;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Collisions")
	UCapsuleComponent* AttackCollision;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Collisions")
	UCapsuleComponent* SlamPushCollision;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Collisions")
	USphereComponent* SlamDownCollision;

	//Player HUD
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UPlayerHUD* PlayerHUD;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	//TSubclassOf<UUserWidget> PlayerHUDClass;

	//Stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxHp = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float CurrentHp = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxEp = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float CurrentEp = 300.0f;

	
	//State
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "State")
	EPlayerState WukongState;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "State")
	EAttackState AttackState;

	UPROPERTY(BlueprintReadWrite, Category = "State")
	FName NextCombo;
	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool bCanMove = true;
};
