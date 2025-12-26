#pragma once
#include "IShape.h"

class Circle final : public IShape {
public:
	explicit Circle(float radius)
		: radius_(radius) {
	}

	void Size() override;
	void Draw() const override;

private:
	float radius_ = 0.0f;
};
