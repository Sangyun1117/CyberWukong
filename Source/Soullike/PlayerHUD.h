// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class SOULLIKE_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//실제 구현은 WBP에서 구현
	//Player HUD HP 설정 함수
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Bar")
	void SetHp(float CurrentHp, float MaxHp);

	//Player HUD EP 설정 함수
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Bar")
	void SetEp(float CurrentEp, float MaxEp);

};
