// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
// Sets default values
AMonster::AMonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMonster::StartSlamKnockback()
{
	//������ġ�� �ణ �ø���. �˹�� �� ���̺��� ���Ͱ� ū ��� ���� �ε����� ���̽� ����
	AddActorWorldOffset(FVector(0, 0, 30), false, nullptr, ETeleportType::None);
	//�̵��� ��Ȱ��ȭ�Ѵ�.
	GetCharacterMovement()->DisableMovement();
	//�˹���·� ����� Tick()���� ���� ���Ͱ� ���� �����̵��� �Ѵ�.
	bIsSlamKnockback = true;
}

void AMonster::EndSlamKnockback()
{
	//�̵� Ȱ��ȭ
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking, 0);
	bIsSlamKnockback = false;
	//���͸� �ణ ����.
	GetCharacterMovement()->AddImpulse(FVector(0, 0, 300), true);
}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsSlamKnockback) {
		// �÷��̾� ������ ���̷�Ż �޽� ��������
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if (!PlayerPawn) return;
		USkeletalMeshComponent* SkeletalMesh = PlayerPawn->FindComponentByClass<USkeletalMeshComponent>();
		if (!SkeletalMesh) return;
		//���� ��ġ ��������
		FVector BongEndSocketLocation = SkeletalMesh->GetSocketLocation(TEXT("weapon_B_front_r_socket"));
		FVector NewLocation(BongEndSocketLocation.X, BongEndSocketLocation.Y, GetActorLocation().Z);
		//���� ��ġ ���� ��ġ�� �̵�
		SetActorLocation(NewLocation, true, nullptr, ETeleportType::None);
	}

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

