#pragma once
#include "Vector2.h"

inline bool HitCircleCircle(const Vector2& aPos, float aR, const Vector2& bPos, float bR) {
	const Vector2 d = aPos - bPos;
	const float r = aR + bR;
	return LengthSq(d) <= r * r;
}