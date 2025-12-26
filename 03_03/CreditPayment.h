#pragma once
#include "Payment.h"

class CreditCardPayment final : public Payment {
public:
	explicit CreditCardPayment(double feeRate)
		: feeRate_(feeRate) {
	}

	std::string Name() const override;

	int PayAndPrintProcess(int subtotalYen) const override;

private:
	double feeRate_;
};
