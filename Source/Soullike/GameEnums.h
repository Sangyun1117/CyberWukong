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