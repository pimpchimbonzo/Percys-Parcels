// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "NormalAIBehavior.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Custum static Mesh"));
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UNormalAIBehavior ai1;
	AMainCharacter player;

    //setting up player
    player.setHealth(100.0);
    player.setDefence(1.0);
    player.setExp(0);

    player.setWeapon("Hand", 10.0);

    ai1.setHealth(100.0);
    ai1.setDamage(5.0);
    ai1.setExp(25.0);

    player.setPlayer(player.getHealth(), player.getDamage(), player.getDefence(), player.getDefence());
    ai1.setAI(ai1.getHealth(), ai1.getDamage(), ai1.getExp());

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

