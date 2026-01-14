#pragma once
#include <Novice.h>

class InputManager {
public:
	void Update();

	const char* GetKeys() const { return keys_; }
	const char* GetPreKeys() const { return preKeys_; }

	bool IsDown(int dik) const;
	bool IsPressed(int dik) const;  // 押した瞬間
	bool IsReleased(int dik) const; // 離した瞬間

private:
	char keys_[256] = {0};
	char preKeys_[256] = {0};
};

// どこからでも参照できるようにする
extern InputManager* gInput;
