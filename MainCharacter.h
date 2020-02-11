// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCharacter.generated.h"

UCLASS()
class POSTGAME2_API AMainCharacter : public AActor
{
	GENERATED_BODY()

	
	
public:	
	// Sets default values for this actor's properties
	AMainCharacter();
	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float Health;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float Exp;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float Tossing;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float Hitting;

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		class USoundBase* Walking;

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		class USoundBase* Tossing;

	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		class USoundBase* Hitting;

	static const FName MoveForwardBinding;
	static const FName MoveSidewaysBinding;

private:
	uint32 bCanToss : 1;
	FTimerHandle TimerHandle_TossTimerExpired;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
