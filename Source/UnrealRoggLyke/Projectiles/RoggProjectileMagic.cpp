// Fill out your copyright notice in the Description page of Project Settings.

#include "RoggProjectileMagic.h"

#include "Components/SphereComponent.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

ARoggProjectileMagic::ARoggProjectileMagic()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->SetSphereRadius(16.f);
	SphereComponent->SetCollisionProfileName("Projectile");

	LoopedNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LoopedNiagraComponent"));
	LoopedNiagaraComponent->SetupAttachment(SphereComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 2000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;
}

void ARoggProjectileMagic::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SphereComponent->OnComponentHit.AddDynamic(this, &ARoggProjectileMagic::OnActorHit);
}

void ARoggProjectileMagic::OnActorHit(
	UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// TODO: Create a damage type for magic projectiles
	TSubclassOf<UDamageType> DamageTypeClass = UDamageType::StaticClass();
	UGameplayStatics::ApplyDamage(OtherActor, 10.f, GetInstigatorController(), this, DamageTypeClass);

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ExplosionEffect, GetActorLocation());

	Destroy();
}
