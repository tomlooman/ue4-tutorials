
#pragma once

#include "UsableActor.generated.h"


UCLASS()
class AUsableActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintImplementableEvent)
	void OnUsed(ACharacter* character);

	UFUNCTION(BlueprintImplementableEvent)
	void StartFocusItem();

	UFUNCTION(BlueprintImplementableEvent)
	void EndFocusItem();
};