#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MonsterStat.generated.h"

USTRUCT(BlueprintType)
struct FMonsterStat : public FTableRowBase {
	GENERATED_BODY()

	//HealthPower, Attack, Defence, WalkSpeed, ChaseSpeed, SkillMultiplier1, SkillMultiplier2, SkillMultiplier3, SkillRange1, SkillRange2, SkillRange3
	FMonsterStat():
		HealthPower(0.0f),
		Attack(0.0f),
		Defence(0.0f),
		WalkSpeed(0.0f),
		ChaseSpeed(0.0f),
		SkillMultiplier1(0.0f),
		SkillMultiplier2(0.0f),
		SkillMultiplier3(0.0f),
		SkillRange1(0.0f),
		SkillRange2(0.0f),
		SkillRange3(0.0f) {}
	
	//두 구조체를 더하는 연산자 오버로딩
	//포인터 연산을 이용한 덧셈처리.
	//포인터로 접근하는것은 굉장히 위험함. vtable 있으면 위험. 바꿔야함.
	FMonsterStat operator+(const FMonsterStat& Other) const 
	{
		const float* const ThisPtr = reinterpret_cast<const float* const>(this);
		const float* const OtherPtr = reinterpret_cast<const float* const>(&Other);
		FMonsterStat Result;

		float* ResultPtr = reinterpret_cast<float*>(&Result);
		int32 StatNum = sizeof(FMonsterStat) / sizeof(float);
		for (int32 i = 0; i < StatNum; ++i) {
			ResultPtr[i] = ThisPtr[i] + OtherPtr[i];
		}
		return Result;
	}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float HealthPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Defence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float ChaseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float SkillMultiplier1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float SkillMultiplier2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float SkillMultiplier3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float SkillRange1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float SkillRange2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float SkillRange3;


};