// © 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "EtherealPlayerMaster.h"

// Sets default values
AEtherealPlayerMaster::AEtherealPlayerMaster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/EtherealParty/Apprentice/Erika_Archer.Erika_Archer'"));
	//static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/Apprentice/Mixamo_Skeleton_Erika_Anim.Mixamo_Skeleton_Erika_Anim'"));

	//GetMesh()->SkeletalMesh = SkeletalMeshObject.Object;
	//GetMesh()->SetAnimInstanceClass(AnimBP.Object->GetAnimBlueprintGeneratedClass());
}

// Called when the game starts or when spawned
void AEtherealPlayerMaster::BeginPlay()
{
	Super::BeginPlay();

	// Gets and stores a reference to the Player State
	EtherealPlayerState = Cast<AEtherealPlayerState>(GetController()->PlayerState);

	if (EtherealPlayerState)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "EtherealPlayerState reference was successfully initialized from code.");
		EtherealPlayerState->Player = this;  // Sets a reference to itself inside the PlayerState
		EtherealPlayerState->Regen();  // start the regen tick
		EtherealPlayerState->Refresh();  // start the refresh tick
	}
}

// Stops the player's movement
void AEtherealPlayerMaster::StopMovement()
{
	GetCharacterMovement()->StopMovementImmediately();
	SpeedForward = 0;
	SpeedRight = 0;
}

