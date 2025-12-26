#include "Rectangle.h"
#include <iostream>

void Rectangle::Size() {
    area_ = width_ * height_;
}

void Rectangle::Draw() const {
    std::cout << "[Rectangle]\n";
    std::cout << "  width  = " << width_ << "\n";
    std::cout << "  height = " << height_ << "\n";
    std::cout << "  area   = " << area_ << "\n\n";
}
