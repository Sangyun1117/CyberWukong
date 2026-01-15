// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/GameEnums.h"
#include "Minimap.generated.h"

/**
 * 
 */
UCLASS()
class SOULLIKE_API UMinimap : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Map")
	void MinimapChange(EMapSection NewMapSection);
};
