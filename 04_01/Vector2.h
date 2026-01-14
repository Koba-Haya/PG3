#pragma once
#include <cmath>

struct Vector2 {
	float x = 0.0f;
	float y = 0.0f;

	Vector2() = default;
	Vector2(float _x, float _y) : x(_x), y(_y) {}
};

inline Vector2 operator+(const Vector2& a, const Vector2& b) { return Vector2(a.x + b.x, a.y + b.y); }
inline Vector2 operator-(const Vector2& a, const Vector2& b) { return Vector2(a.x - b.x, a.y - b.y); }
inline Vector2 operator*(const Vector2& a, float s) { return Vector2(a.x * s, a.y * s); }

inline float Dot(const Vector2& a, const Vector2& b) { return a.x * b.x + a.y * b.y; }
inline float LengthSq(const Vector2& v) { return Dot(v, v); }

inline float Clamp(float v, float mn, float mx) {
	if (v < mn)
		return mn;
	if (v > mx)
		return mx;
	return v;
}
