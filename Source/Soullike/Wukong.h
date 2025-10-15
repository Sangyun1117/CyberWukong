// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "Wukong.generated.h"

class UDamageReceiver;
class UUserWidget;
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

private:
	//사용자 키입력
	void OnHitMove(const FInputActionValue& Value);
	void OnHitLook(const FInputActionValue& Value);
	void OnHitRoll(const FInputActionValue& Value);

	//UFUNCTION()
	//void OnHpChanged(float CurrentHp, float MaxHp);

	//UFUNCTION()
	//void OnDead();


protected:
	//입력 매핑 변수
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Look;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Roll;

	//블루프린트에서 세팅되는 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHp = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UDamageReceiver* DamageReceiver;

	//Player HUD
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TObjectPtr<UUserWidget> PlayerHUD;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDClass;


};
