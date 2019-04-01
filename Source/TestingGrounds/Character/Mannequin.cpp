// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "Components/ChildActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Weapons/Gun.h"
#include "NPC/PatrolRoute.h"


// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-35.0f, 8.75f, 39.0f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
	
	// Create a child actor that will be used to spawn a gun
	GunActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("GunActor"));
	//TODO FIX SOCKET
	GunActor->SetupAttachment(Mesh1P, TEXT("GripPoint"));

	// Create a patrol route component
	PatrolRoute = CreateDefaultSubobject<UPatrolRoute>(TEXT("PatrolRoute"));
}

// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();
	if (SkeletalMesh1P != nullptr) { Mesh1P->SetSkeletalMesh(SkeletalMesh1P); }
	if (AnimInstance1P != nullptr) { Mesh1P->SetAnimInstanceClass(AnimInstance1P); }
		
	if (GunBP != nullptr)
	{
		GunActor->SetChildActorClass(GunBP);
		GunActor->CreateChildActor();
		//TODO SET UP SOCKET
	}
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMannequin::Fire()
{
	AGun* Gun = Cast<AGun>(GunActor->GetChildActor());
	Gun->OnFire();
}

