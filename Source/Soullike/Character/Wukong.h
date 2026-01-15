// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "Core/GameEnums.h"
#include "Wukong.generated.h"

class UDamageReceiver;
class UUserWidget;
class USphereComponent;
class UCapsuleComponent;
class UPlayerHUD;
class UMinimap;
class UInteractionText;
class AMonster;
class UMaterialInstanceDynamic;

UCLASS()
class SOULLIKE_API AWukong : public ACharacter
{
	GENERATED_BODY()

public:
	AWukong();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//미니맵 변경
	UFUNCTION(BlueprintCallable, Category = "UI")
	void MinimapChange(EMapSection NewSection);

	UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnAttackCollisionChanged(bool bEnabled);
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnSlamPushCollisionChanged(bool bEnabled);
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnSlamDownCollisionChanged(bool bEnabled);
	UFUNCTION(BlueprintCallable, Category = "Game")
	void GetKey();

protected:
	virtual void BeginPlay() override;
	//사용자 키입력
	void OnHitMove(const FInputActionValue& Value);
	void OnHitLook(const FInputActionValue& Value);
	void OnHitJump(const FInputActionValue& Value);
	void OnHitRoll(const FInputActionValue& Value);
	void OnHitAttack(const FInputActionValue& Value);
	void OnHitSlam(const FInputActionValue& Value);

	//몽타주 재생
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Animation")
	void PlayMontage(EEffectType Effect);
	//SlamPush시 벽 충돌 체크
	UFUNCTION(BlueprintCallable)
	void SlamPushWallCheck();
	//플레이어를 가리는 장애물을 투명화 시킴
	UFUNCTION(BlueprintCallable)
	void TransparencyDecorations();

private:

	UFUNCTION()
	void OnHpChanged(float HealthPower, float MaxHealthPower);

	UFUNCTION()
	void OnDead();

	UFUNCTION(BlueprintCallable)
	void SetState(EPlayerState NewState);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowInteraction(FText NewText);

	UFUNCTION()
	void OnAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnSlamPushBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnSlamDownBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


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

	//UI
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UPlayerHUD* PlayerHUD;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UMinimap* Minimap;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UInteractionText* InteractionText;

	//Stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxHp = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float CurrentHp = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxEp = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float CurrentEp = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float SlamEp = 30.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float BaseDamage = 10.0f;

	//State
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "State")
	EPlayerState WukongState;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "State")
	EAttackState AttackState;

	UPROPERTY(BlueprintReadWrite, Category = "State")
	FName NextCombo;
	UPROPERTY(BlueprintReadWrite, Category = "State")
	int32 ComboCount = 0;
	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool bCanMove = true;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EMapSection NowMapSection = EMapSection::SewerB2F;
	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool bIsKey = false;

	//Slam
	UPROPERTY(BlueprintReadWrite, Category = "Slam")
	AMonster* SlemdMonster;
	UPROPERTY(BlueprintReadWrite, Category = "Slam")
	bool bIsSlamAnim = false;

	//투명화 타겟
	TArray<UMaterialInstanceDynamic*> TransparentTargets;
private:
	FTimerHandle InteractionTimerHandle;
};
