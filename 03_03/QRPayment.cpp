#include "QRPayment.h"
#include <iostream>

std::string QRPayment::Name() const { return "QR決済"; }

int QRPayment::PayAndPrintProcess(int subtotalYen) const {
	std::cout << "  [手順] 小計 = " << subtotalYen << "円\n";
	std::cout << "  [手順] ポイント還元率 = " << pointBackPercent_ << "%\n";

	int points = (subtotalYen * pointBackPercent_) / 100;

	std::cout << "  [手順] 還元ポイント = " << subtotalYen << " * " << pointBackPercent_
		<< "% = " << (subtotalYen * pointBackPercent_) / 100.0
		<< " -> 切り捨てて " << points << "pt\n";

	int total = subtotalYen;
	std::cout << "  [結果] 支払い金額 = " << total << "円（ポイント " << points << "pt 付与）\n";
	return total;
}
