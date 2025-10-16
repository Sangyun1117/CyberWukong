#pragma once

#include "CoreMinimal.h"
#include "GameEnums.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	Peace	UMETA(DisplayName = "Peace"),
	Dead	UMETA(DisplayName = "Dead"),
	Roll	UMETA(DisplayName = "Roll"),
};
UENUM(BlueprintType)
enum class EAttackState : uint8
{
	None		UMETA(DisplayName = "None"),
	Hit			UMETA(DisplayName = "Hit"),
	Combo		UMETA(DisplayName = "Combo"),
	Recovery	UMETA(DisplayName = "Recovery"),
	SlamPush	UMETA(DisplayName = "SlamPush"),
	SlamDown	UMETA(DisplayName = "SlamDown"),
};