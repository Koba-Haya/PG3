#include <vector>
#include <memory>

#include "Circle.h"
#include "Rectangle.h"

int main() {
	std::vector<std::unique_ptr<IShape>> shapes;
	shapes.emplace_back(std::make_unique<Circle>(3.0f));
	shapes.emplace_back(std::make_unique<Rectangle>(4.0f, 5.0f));
	shapes.emplace_back(std::make_unique<Circle>(1.5f));
	shapes.emplace_back(std::make_unique<Rectangle>(2.0f, 7.0f));

	for (const auto& s : shapes) {
		s->Size();
		s->Draw();
	}

	return 0;
}
