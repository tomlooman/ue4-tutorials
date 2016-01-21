
#pragma once

#include "UsableActor.generated.h"


UCLASS()
class AUsableActor : public AActor
{
	GENERATED_BODY()

public:

	// The functions return a boolean to force Unreal to recognize it as Functions instead of Events so they can be overridden in Blueprint child classes.

	UFUNCTION(BlueprintImplementableEvent)
	bool OnUsed(ACharacter* Character);

	UFUNCTION(BlueprintImplementableEvent)
	bool OnBeginFocus();

	UFUNCTION(BlueprintImplementableEvent)
	bool OnEndFocus();
};