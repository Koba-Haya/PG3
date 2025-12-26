#include "Circle.h"
#include <iostream>

void Circle::Size() {
	constexpr float pi = 3.14159265358979323846f;
	area_ = pi * radius_ * radius_;
}

void Circle::Draw() const {
	std::cout << "[Circle]\n";
	std::cout << "  radius = " << radius_ << "\n";
	std::cout << "  area   = " << area_ << "\n\n";
}
