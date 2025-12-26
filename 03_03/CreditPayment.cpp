#include "CreditPayment.h"
#include <iostream>

std::string CreditCardPayment::Name() const { return "クレジットカード"; }

int CreditCardPayment::PayAndPrintProcess(int subtotalYen) const {
	std::cout << "  [手順] 小計 = " << subtotalYen << "円\n";
	std::cout << "  [手順] カード手数料率 = " << (feeRate_ * 100.0) << "%\n";

	double fee = static_cast<double>(subtotalYen) * feeRate_;
	int feeYen = static_cast<int>(fee + 0.5);

	std::cout << "  [手順] 手数料 = " << subtotalYen << " * " << feeRate_
		<< " = " << fee << " -> 四捨五入して " << feeYen << "円\n";

	int total = subtotalYen + feeYen;
	std::cout << "  [結果] 支払い金額 = 小計 " << subtotalYen << " + 手数料 " << feeYen
		<< " = " << total << "円\n";
	return total;
}
