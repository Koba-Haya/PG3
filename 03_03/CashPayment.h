#pragma once
#include "Payment.h"

class CashPayment final : public Payment {
public:
	std::string Name() const override;

	int PayAndPrintProcess(int subtotalYen) const override;
};
