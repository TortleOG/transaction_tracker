#include <iostream>

#include "transaction.h"

int main() {
	tt::Transaction transact { 1, "mcdonalds", 20.f };

	transact.print();

	std::cout << "ID: " << transact.get_id() << std::endl;
	std::cout << "NAME: " << transact.get_name() << std::endl;
	std::cout << "AMOUNT: " << transact.get_amount() << std::endl;
	std::cout << "DATE: " << transact.get_date() << std::endl;

	return 0;
}

