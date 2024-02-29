// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABCharacterControlData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterControlData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UABCharacterControlData();

	//Yaw값 체크 여부
	UPROPERTY(EditAnywhere, Category = Pawn)
	uint32 bUseControllerRotationYaw : 1;


	//무브먼트 사용 변수
	UPROPERTY(EditAnywhere, Category = CharacterMovement)
	uint32 bOrientRotationToMovement : 1;

	UPROPERTY(EditAnywhere, Category = CharacterMovement)
	uint32 bUseControllerDesiredRotation : 1;

	UPROPERTY(EditAnywhere, Category = CharacterMovement)
	FRotator RotationRate;


	//입력 매핑 컨텍스트를 담음
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputMappingContext> InputMappingContext;


	//스프링암 관련 변수
	UPROPERTY(EditAnywhere, Category = SpringArm)
	float TargetArmLength;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	FRotator RelativeRotation;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	uint32 bUsePawnControlRotation : 1;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	uint32 bInheritPitch : 1;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	uint32 bInheritYaw : 1;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	uint32 bInheritRoll : 1;

	UPROPERTY(EditAnywhere, Category = SpringArm)
	uint32 bDoCollisionTest : 1;
	
};
