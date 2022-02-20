// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ThirdPersonComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TITRAN_API UThirdPersonComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UThirdPersonComponent();

	FVector ActorDistance = FVector(0.0f, 30.0f, 0.0f);

	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) class UCameraComponent* Camera;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
