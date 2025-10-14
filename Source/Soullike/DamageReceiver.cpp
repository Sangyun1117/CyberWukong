// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageReceiver.h"
#include "TimerManager.h"

void UDamageReceiver::SetHp(float MaxHp)
{
	MaxHealthPower = MaxHp;
	CurrentHealthPower = MaxHp;
}

void UDamageReceiver::OnDamageReceived(float Damage)
{
	if (!bIsVulnerable || Damage <= 0.f)
	{
		return;
	}

	// 데미지 적용
	CurrentHealthPower -= Damage;
	CurrentHealthPower = FMath::Clamp(CurrentHealthPower, 0.f, MaxHealthPower);

	// 체력 변경 이벤트 호출
	OnHealthPowerChanged.Broadcast(CurrentHealthPower, MaxHealthPower);

	// 죽음 처리
	if (CurrentHealthPower <= 0.f)
	{
		CurrentHealthPower = 0.f;
		OnDead.Broadcast();
	}

	// 피격 후 무적 상태
	bIsVulnerable = false;
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_ReturnToVulnerable, this, &UDamageReceiver::ReturnToVulnerable, InvulnerableTime, false);
	}

}

void UDamageReceiver::ReturnToVulnerable()
{
	bIsVulnerable = true;
}




