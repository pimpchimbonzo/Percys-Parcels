// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCharacter.generated.h"
#include <string>

UCLASS()
class POSTGAME2_API AMainCharacter : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMainCharacter();

	UPROPERTY(VisibleAnywhere, Category= "Percy")
		UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
        float getHealth() {
        return health;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    float getExp() {
        return exp;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    float getDamage() {
        return damage;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    float getDefence() {
        return defence;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setHealth(float hp) {
        hp = health;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setExp(float EXP) {
        EXP = exp;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    std::string getWeapon() {
        return _weapon;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setWeapon(std::string weapon, float dmg) {
        _weapon = weapon;
        dmg = damage;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setDefence(float df) {
        df = defence;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setPlayer(float hp, float dmg, float df, float EXP) {
        hp = health;
        dmg = damage;
        df = defence;
        EXP = exp;
    }

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
    float health;
    float exp;
    float damage;
    float defence;
    std::string _weapon;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
