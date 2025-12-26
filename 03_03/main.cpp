#include "CashPayment.h"
#include "QRPayment.h"
#include "CreditPayment.h"

#include <iostream>
#include <memory>
#include <vector>

int main() {
	std::cout << "=== 飲食店の会計（支払い方法） ===\n\n";

	std::vector<int> itemPricesYen = { 780, 420, 1200 };
	std::cout << "[注文内容]\n";
	for (size_t i = 0; i < itemPricesYen.size(); ++i) {
		std::cout << "  商品" << (i + 1) << " : " << itemPricesYen[i] << "円\n";
	}

	int subtotal = CalcSubtotalYen(itemPricesYen);
	std::cout << "\n[小計計算]\n";
	std::cout << "  小計 = 780 + 420 + 1200 = " << subtotal << "円\n\n";

	std::vector<std::unique_ptr<Payment>> methods;
	methods.emplace_back(std::make_unique<CashPayment>());
	methods.emplace_back(std::make_unique<CreditCardPayment>(0.035));
	methods.emplace_back(std::make_unique<QRPayment>(3));

	std::cout << "=== 支払い方法ごとの実行 ===\n\n";
	for (const auto& method : methods) {
		std::cout << "[支払い方法] " << method->Name() << "\n";
		int total = method->PayAndPrintProcess(subtotal);
		std::cout << "  [まとめ] 最終支払い = " << total << "円\n";
		std::cout << "----------------------------------------\n";
	}

	std::cout << "\n=== ここまで ===\n";
	return 0;
}
