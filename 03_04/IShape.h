#pragma once

class IShape {
public:
	virtual ~IShape() = 0;
	virtual void Size() = 0;
	virtual void Draw() const = 0;

protected:
	float area_ = 0.0f;
};