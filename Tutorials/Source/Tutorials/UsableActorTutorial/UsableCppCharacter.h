

#pragma once

#include "GameFramework/Character.h"
#include "UsableCppCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIALS_API AUsableCppCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	AUsableCppCharacter();

	virtual void Tick(float DeltaSeconds) override;

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FirstPersonCameraComponent;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	/** Get actor derived from UsableActor currently looked at by the player */
	class AUsableActor* GetUsableInView();

	/* Max distance to use/focus on actors. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float MaxUseDistance;

	/* True only in first frame when focused on new usable actor. */
	bool bHasNewFocus;

	/* Actor derived from UsableActor currently in center-view. */
	AUsableActor* FocusedUsableActor;

public:

	/** Use the actor currently in view (if derived from UsableActor) */
	UFUNCTION(BlueprintCallable, WithValidation, Server, Reliable, Category = "Pawn")
	virtual void Use();
};
