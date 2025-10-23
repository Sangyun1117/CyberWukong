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
	//몬스터위치를 약간 올린다. 넉백시 봉 높이보다 몬스터가 큰 경우 땅에 부딪히는 케이스 방지
	AddActorWorldOffset(FVector(0, 0, 30), false, nullptr, ETeleportType::None);
	//이동을 비활성화한다.
	GetCharacterMovement()->DisableMovement();
	//넉백상태로 만들어 Tick()에서 봉과 몬스터가 같이 움직이도록 한다.
	bIsSlamKnockback = true;
}

void AMonster::EndSlamKnockback()
{
	//이동 활성화
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking, 0);
	bIsSlamKnockback = false;
	//몬스터를 약간 띄운다.
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
		// 플레이어 폰에서 스켈레탈 메시 가져오기
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if (!PlayerPawn) return;
		USkeletalMeshComponent* SkeletalMesh = PlayerPawn->FindComponentByClass<USkeletalMeshComponent>();
		if (!SkeletalMesh) return;
		//소켓 위치 가져오기
		FVector BongEndSocketLocation = SkeletalMesh->GetSocketLocation(TEXT("weapon_B_front_r_socket"));
		FVector NewLocation(BongEndSocketLocation.X, BongEndSocketLocation.Y, GetActorLocation().Z);
		//몬스터 위치 소켓 위치로 이동
		SetActorLocation(NewLocation, true, nullptr, ETeleportType::None);
	}

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

