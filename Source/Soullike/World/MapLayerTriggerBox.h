// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Core/GameEnums.h"
#include "MapLayerTriggerBox.generated.h"


class UArrowComponent;

UCLASS()
class SOULLIKE_API AMapLayerTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	AMapLayerTriggerBox();
protected:
	virtual void BeginPlay() override;

	/** 오버랩 시작 이벤트 */
	UFUNCTION()
	void TriggerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void TriggerEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

private:
	void HandleOverlap(AActor* OtherActor, bool bIsBeginOverlap);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMapSection FrontSection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMapSection BackSection;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UArrowComponent> Arrow;
};
