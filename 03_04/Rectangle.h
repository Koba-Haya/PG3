#pragma once
#include "IShape.h"

class Rectangle final : public IShape {
public:
    Rectangle(float width, float height)
        : width_(width), height_(height) {
    }

    void Size() override;
    void Draw() const override;

private:
    float width_ = 0.0f;
    float height_ = 0.0f;
};
