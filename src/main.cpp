#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

struct transaction {
	int id;
	std::string title;
	float amount;
	std::string date_created;
};

std::string get_date();
transaction create_transact(const int&);
void print_transact(std::ostream&, const transaction&);

int main() {
	int last_id = -1;

	transaction transac = create_transact(last_id);

	// Print transaction
	print_transact(std::cout, transac);

	return 0;
}

/**
 * Gets the current date on the system and returns a
 * formatted string.
 */
std::string get_date() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	int month = now->tm_mon + 1,
			day = now->tm_mday,
			year = now->tm_year + 1900;

	std::string date = std::to_string(month) + '/' + std::to_string(day) + '/' + std::to_string(year);

	return date;
}

/**
 * Creates a new transaction.
 */
transaction create_transact(const int& last_id) {
	transaction t;
	std::cout << "NEW TRANSACTION\n" + std::string(15, '=');

	std::cout << "(Title) ";
	std::getline(std::cin, t.title);

	std::cout << "(Amount) ";
	std::cin >> t.amount;

	t.id = last_id + 1;

	t.date = get_date();
}

/**
 * Prints out the data of a given transaction.
 */
void print_transact(std::ostream& os, const transaction& t) {
	os << "\n\nTRANSACTION (#" << t.id << ") : "
		 << "\nNAME: " << t.title
		 << "\nAMOUNT: " << t.amount
		 << "\nDATE_CREATED: " << t.date_created;
}

