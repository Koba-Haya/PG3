#include "Payment.h"

int CalcSubtotalYen(const std::vector<int>& itemPricesYen) {
	int sum = 0;
	for (int price : itemPricesYen) {
		sum += price;
	}
	return sum;
}
