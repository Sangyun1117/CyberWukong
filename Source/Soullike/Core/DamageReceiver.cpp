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

	// ������ ����
	CurrentHealthPower -= Damage;
	CurrentHealthPower = FMath::Clamp(CurrentHealthPower, 0.f, MaxHealthPower);

	// ü�� ���� �̺�Ʈ ȣ��
	OnHealthPowerChanged.Broadcast(CurrentHealthPower, MaxHealthPower);

	// ���� ó��
	if (CurrentHealthPower <= 0.f)
	{
		CurrentHealthPower = 0.f;
		OnDead.Broadcast();
	}

	// �ǰ� �� ���� ����
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




