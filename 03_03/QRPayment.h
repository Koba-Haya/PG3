#pragma once
#include "Payment.h"

class QRPayment final : public Payment {
public:
	explicit QRPayment(int pointBackPercent)
		: pointBackPercent_(pointBackPercent) {
	}

	std::string Name() const override;

	int PayAndPrintProcess(int subtotalYen) const override;

private:
	int pointBackPercent_;
};
