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
UENUM(BlueprintType)
enum class EEffectType : uint8
{
	Attack		UMETA(DisplayName = "Attack"),
	Roll		UMETA(DisplayName = "Roll"),
	SlamPush	UMETA(DisplayName = "SlamPush"),
	SlamDown	UMETA(DisplayName = "SlamDown"),
};
UENUM(BlueprintType)
enum class EMapSection : uint8
{
	SewerB1F			UMETA(DisplayName = "SewerB1F"),
	SewerB1FtoB2F		UMETA(DisplayName = "SewerB1FtoB2F"),
	SewerB2F			UMETA(DisplayName = "SewerB2F"),
};
