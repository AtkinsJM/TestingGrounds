// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimInstance.h"
#include "Gun.generated.h"

UCLASS()
class TESTINGGROUNDS_API AGun : public AActor
{
	GENERATED_BODY()

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Fires the gun
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void OnFire();

	void SetAnimInstance(UAnimInstance* Instance);

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABallProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		FVector MuzzleLocation = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		FRotator MuzzleRotation = FRotator(0.0f, 90.0f, 0.0f);

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;
	   
	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimInstance* AnimInstance;
};
