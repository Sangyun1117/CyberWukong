// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"

class UDamageReceiver;
class USphereComponent;
class UPawnSensingComponent;

UCLASS()
class SOULLIKE_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	AMonster();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void StartSlamKnockback();
	UFUNCTION(BlueprintCallable)
	void EndSlamKnockback();
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool bIsSlamKnockback = false;

	//컴포넌트
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Collisions")
	USphereComponent* AttackCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UDamageReceiver* DamageReceiver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UPawnSensingComponent* PawnSensing;
};
