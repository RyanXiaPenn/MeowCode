// Copyright Ryan Xia 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEOWCODE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//void OpenDoor();
	//void CloseDoor();

	float GetTotalMassOfActorsOnPlate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpenRequest;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;
private:
	//UPROPERTY(EditAnywhere)
	//float OpenAngle = -90.0f;
	//UPROPERTY(EditAnywhere)
	//float DoorCloseDelay = 1.f;
	//float LastDoorOpenTime;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	

	

	//AActor* ActorThatOpens;//Remember pawn inherits from actor
	AActor* Owner;
	
};
