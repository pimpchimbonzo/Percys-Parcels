// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NormalAIBehavior.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POSTGAME2_API UNormalAIBehavior : public UActorComponent
{
	GENERATED_BODY()
private:
    float health;
    float exp;
    float damage;

public:	
	// Sets default values for this component's properties
	UNormalAIBehavior();
	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
        //get float
        float getDamage() {
        return damage;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    float getHealth() {
        return health;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    float getExp() {
        return exp;
    }

    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setHealth(float hp) {
        hp = health;
    }

    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setDamage(float dmg) {
        dmg = damage;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setExp(float EXP) {
        EXP = exp;
    }
    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    void setAI(float hp, float dmg, float EXP) {
        dmg = damage;
        hp = health;
        EXP = exp;
    }

    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    bool kill(bool) {
        if (health == 0 || damage >= health) {
            return true;
        }
        else if (health >= 1 || damage < health) {
            return false;
        }
        else {
            return false;
        }
    }

    UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
    bool hit(bool) {
        if (true) {
            health = health - damage;
        }
        else if (false) {
            return 100;
        }
        else
            return 102;
    }

    UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
        class USoundBase* Walking;

    UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
        class USoundBase* Tossing;

    UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
        class USoundBase* Hitting;

	static const FName MoveForwardBinding;
	static const FName MoveSidewaysBinding;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
