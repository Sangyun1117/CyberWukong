/*
데미지 처리 로직을 수행하는 컴포넌트입니다.
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageReceiver.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDead);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthPowerChanged, float, HealthPower, float, MaxHealthPower);


UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class SOULLIKE_API UDamageReceiver : public UActorComponent
{
	GENERATED_BODY()

public:
	//죽었을 때 호출되는 이벤트
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDead OnDead;

	//체력이 변경될 때 호출되는 이벤트
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthPowerChanged OnHealthPowerChanged;

	//데미지를 받을 때 호출
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void OnDamageReceived(float Damage);

protected:
	//최대체력을 설정해주는 함수
	UFUNCTION(BlueprintCallable)
	void SetHp(float MaxHp);

	//일정 시간 후 무적 상태 해제
	void ReturnToVulnerable();


protected:
	//현재체력: 이 값이 0이 되면 OnDead 이벤트 호출
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hp")	
	float CurrentHealthPower = 100.f;
	//최대체력
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hp")
	float MaxHealthPower = 100.f;
	//현재 피격이 가능한 상태인지 여부
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State")
	bool bIsVulnerable = true;
	//피격 후 무적 상태 지속시간
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State")
	float InvulnerableTime = 0.3f;

	//타이머 핸들
	FTimerHandle TimerHandle_ReturnToVulnerable;
};
