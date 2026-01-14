#include "InputManager.h"
#include <cstring>

InputManager* gInput = nullptr;

void InputManager::Update() {
	std::memcpy(preKeys_, keys_, sizeof(keys_));
	Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::IsDown(int dik) const { return keys_[dik] != 0; }

bool InputManager::IsPressed(int dik) const { return (preKeys_[dik] == 0) && (keys_[dik] != 0); }

bool InputManager::IsReleased(int dik) const { return (preKeys_[dik] != 0) && (keys_[dik] == 0); }
