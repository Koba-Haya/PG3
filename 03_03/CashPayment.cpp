#include "CashPayment.h"
#include <iostream>

std::string CashPayment::Name() const { return "現金"; }

int CashPayment::PayAndPrintProcess(int subtotalYen) const {
	std::cout << "  [手順] 小計 = " << subtotalYen << "円\n";
	std::cout << "  [手順] 現金は手数料なし\n";
	int total = subtotalYen;
	std::cout << "  [結果] 支払い金額 = " << total << "円\n";
	return total;
}
