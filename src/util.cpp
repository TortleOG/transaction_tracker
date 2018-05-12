#include "util.h"

#include <ctime>
#include <string>

/**
 * Gets the current date on the system and returns a
 * formatted string.
 */
std::string tt::util::create_date() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	int month = now->tm_mon + 1,
			day = now->tm_mday,
			year = now->tm_year + 1900;

	std::string date = std::to_string(month) + '/' + std::to_string(day) + '/' + std::to_string(year);

	return date;
}
