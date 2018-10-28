// Fill out your copyright notice in the Description page of Project Settings.

#include "GlobalFire.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AGlobalFire::AGlobalFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> CompleteFireBP(TEXT("Blueprint'/Game/CompleteFireBP.CompleteFireBP'"));
	if (CompleteFireBP.Object) {
		CompleteFireBPClass = (UClass*)CompleteFireBP.Object->GeneratedClass;
	}

}

// Called when the game starts or when spawned
void AGlobalFire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGlobalFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

