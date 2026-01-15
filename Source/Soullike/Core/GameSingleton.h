#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameSingleton.generated.h"


UCLASS()
class SOULLIKE_API UGameSingleton : public UObject
{
	GENERATED_BODY()

public:
	UGameSingleton();
	//csv 데이터 테이블 가져오기
};
