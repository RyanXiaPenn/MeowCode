// Copyright Ryan Xia 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEOWCODE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	// Ray-cast and Grab what's in reach
	void Grab();
	// Called when grab is released
	void Release();
	
	// Find attached physics handle
	void FindPhysicsHandleComponent();
	// Setup (assuemed) attached input component
	void SetupInputComponent();
	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	// Return current start of reach line
	FVector GetReachLineStart();
	// Return current end of reach line
	FVector GetReachLineEnd();
};
