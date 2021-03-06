// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS(config = Game)
class FRAMEWORK_API AProjectile : public AActor {

	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	class UStaticMeshComponent* MeshComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

public:
	AProjectile();

	/** inits velocity of the projectile in the shoot direction */
	void InitVelocity(const FVector& ShootDirection);

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UStaticMeshComponent* GetMeshComponent() const { return MeshComp; }
};

