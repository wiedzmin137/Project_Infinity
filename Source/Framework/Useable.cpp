// CC BY-NC 4.0

#include "Framework.h"
#include "Useable.h"

AUseable::AUseable() {
	bIsCollectable = false;
}

//TODO fix networking authority
void AUseable::Use_Implementation(ABaseCharacter* Character) {
	UseEvent.Broadcast(Character);
}