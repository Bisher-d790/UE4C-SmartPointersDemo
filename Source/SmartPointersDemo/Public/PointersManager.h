// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointersManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAction);

UCLASS()
class SMARTPOINTERSDEMO_API APointersManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APointersManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma region Shared Pointer
private:
	UPROPERTY(EditDefaultsOnly, Category = "Shared Pointer")
		TSubclassOf<class APointerReferencedActor> SharedPointerClass = nullptr;

	TSharedPtr<class APointerReferencedActor> SharedPointerObjectPtr = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Shared Pointer")
		TArray<class APointerReferencer*> SharedPointerReferencers;

	UPROPERTY(EditInstanceOnly, Category = "Shared Pointer")
		AActor* SharedPointerObjectSpawnPos;

	UPROPERTY(BlueprintAssignable, Category = "Shared Pointer")
		FOnAction OnSharedPointerActivated;

	UPROPERTY(BlueprintAssignable, Category = "Shared Pointer")
		FOnAction OnSharedPointerDeactivated;

public:
	TSharedPtr<class APointerReferencedActor> GetSharedPointerRef();

	UFUNCTION(BlueprintCallable, Category = "Shared Pointer")
		FORCEINLINE int GetSharedPointerRefsCount();

	void OnSharedPointerDereferenced();
#pragma endregion Shared Pointer

};