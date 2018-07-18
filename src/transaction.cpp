#include "transaction.h"

#include <string>
#include <thread>
#include <chrono>
#include <iostream>


#include "util.h"

/**
 * Default Constructor
 */
tt::Transaction::Transaction() { }

tt::Transaction::Transaction(const unsigned int &last_id) {
  this->last_id = last_id;
}

/**
 * Creates a new transaction with a id, name, and the amount of the transaction.
 *
 * The first parameter is a unsigned int which is an id for the transaction.
 * The second parameter is a string which is the name of the transaction.
 * The last parameter is a float for the dollar amount of the transaction.
 */
tt::Transaction::Transaction(const unsigned int &id, const std::string &name, const double &amount) {
  this->id = id;
  this->name = name;
  this->amount = amount;
  this->date_created = tt::util::create_date();
  this->last_id = id - 1;
}

tt::Transaction::Transaction(const unsigned int &id, const std::string &name, const double &amount, const std::string &date)
  : Transaction(id, name, amount) {
  this->date_created = date;
}

/**
 * Prints the details of the transaction to the output.
 * Returns void.
 */
void tt::Transaction::print() {
  std::cout << "TRANSACTION (#" << this->id << ") : "
    << "\nNAME : " << this->name
    << "\nAMOUNT : $" << this->amount
    << "\nDATE CREATED : " << this->date_created << '\n';
}

std::ostream& operator<<(std::ostream &os, const tt::Transaction &t) {
  os << t.get_id() << " " << t.get_name() << " "
    << t.get_amount() << " " << t.get_date();

  return os;
}

std::istream& operator>>(std::istream &is, tt::Transaction &t) {
  std::string name, date;
  double amt;

  std::cout << "Name: ";
  is >> name;

  std::cout << "Amount: ";
  is >> amt;

  std::cout << "Date (MM/DD/YYYY or 'today'): ";
  is >> date;

  if (date == "today")
    date = tt::util::create_date();

  t.set_id(t.get_last_id() + 1).set_name(name).set_amount(amt).set_date(date);

  return is;
}
