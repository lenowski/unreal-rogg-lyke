// Fill out your copyright notice in the Description page of Project Settings.


#include "RoggCharacter.h"

// Sets default values
ARoggCharacter::ARoggCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoggCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoggCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARoggCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

