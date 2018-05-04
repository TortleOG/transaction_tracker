#include <iostream>
#include <string>
#include <ctime>

struct transaction {
	int id;
	std::string title;
	float amount;
	std::string date_created;
};

int main() {
	transaction transac;
	std::cout << "Create new transaction: " << std::endl;
	std::cout << "Title: ";
	std::getline(std::cin, transac.title);
	std::cout << "Amount: ";
	std::cin >> transac.amount;

	// Create transaction id
	int id = 0;
	transac.id = 0;

	// Create transaction date
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	int month = now->tm_mon + 1,
			day = now->tm_mday,
			year = now->tm_year + 1900;
	transac.date_created = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);

	// Print transaction
	std::cout << "\n\nTRANSACTION (#" << transac.id << ") : "
						<< "\nNAME: " << transac.title
						<< "\nAMOUNT: " << transac.amount
						<< "\nDATE_CREATED: " << transac.date_created;

	return 0;
}

