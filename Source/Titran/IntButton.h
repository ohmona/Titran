// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IntButton.generated.h"

UCLASS()
class TITRAN_API AIntButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIntButton();

	UPROPERTY(BlueprintReadOnly, replicated) bool bClicked = false;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Click();
	void Reset();

};
