// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionText.generated.h"

/**
 * 
 */
UCLASS()
class SOULLIKE_API UInteractionText : public UUserWidget
{
	GENERATED_BODY()
public:
	//Player HUD EP 설정 함수
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Bar")
	void SetText(const FText& NewText);
};
