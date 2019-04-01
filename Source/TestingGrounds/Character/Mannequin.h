// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mannequin.generated.h"

class AGun;

UCLASS()
class TESTINGGROUNDS_API AMannequin : public ACharacter
{
	GENERATED_BODY()

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class UChildActorComponent* GunActor;

	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
		class UPatrolRoute* PatrolRoute;
	

public:
	// Sets default values for this character's properties
	AMannequin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
		TSubclassOf<AGun> GunBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		class USkeletalMesh* SkeletalMesh1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		class UClass* AnimInstance1P;

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
	
};
