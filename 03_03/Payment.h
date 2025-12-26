#pragma once
#include <string>
#include <vector>

class Payment {
public:
	virtual ~Payment() = default;

	virtual std::string Name() const = 0;
	virtual int PayAndPrintProcess(int subtotalYen) const = 0;
};

int CalcSubtotalYen(const std::vector<int>& itemPricesYen);
