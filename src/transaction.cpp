#include "transaction.h"

#include <string>
#include <iostream>

#include "util.h"

tt::Transaction::Transaction(unsigned int id, std::string name, float amount) {
  this->id = id;
  this->name = name;
  this->amount = amount;
  this->date_created = tt::util::create_date();
}

void tt::Transaction::print() {
  std::cout << "TRANSACTION (#" << this->id << ") : "
    << "\nNAME : " << this->name
    << "\nAMOUNT : $" << this->amount
    << "\nDATE CREATED : " << this->date_created << std::endl;
}
