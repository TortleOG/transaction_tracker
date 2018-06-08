#include <iostream>
#include <string>

#include "transaction.h"

int main() {
	const std::string header = "WELCOME TO TRANSACTION TRACKER";
	const std::string sep(header.size(), '=');

	std::cout << header << '\n' << sep
		<< "(a) View transactions\n" << "(b) Add transaction\n"
		<< "(c) Remove last transaction\n" << "(d) View net gain/loss\n" << sep;

	tt::Transaction transact { 1, "mcdonalds", 20.f };

	transact.print();

	return 0;
}

