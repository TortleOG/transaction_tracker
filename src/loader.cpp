#include "loader.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "transaction.h"

/**
 * Default Constructor
 */
tt::Loader::Loader() { }

tt::Loader::Loader(std::vector<tt::Transaction> &trns) {
  this->trns = trns;
}

void tt::Loader::parse(std::fstream &fs) {
  std::string tmp_id, name, tmp_amt, date, ln;
  int i = 1;
  while (fs.good()) {
    std::getline(fs, ln, '\n');
    if (ln.size() == 0 && i == 5 ) {
      i = 1;
    } else if (ln.size() == 0 && i != 5) {
      throw std::runtime_error("Incorrectly formed transaction in transaction file.\n");
    } else {
      if (i == 1) tmp_id = ln;
      else if (i == 2) name = ln;
      else if (i == 3) tmp_amt = ln;
      else if (i == 4) {
        date = ln;

        const unsigned int id = std::stoi(tmp_id.substr(1));
        const float amt = std::stof(tmp_amt);

        tt::Transaction tmp { id, name, amt, date };
        this->trns.push_back(tmp);
      }
      ++i;
    }
  }
}

bool tt::Loader::load_file(const std::string &name) {
  std::fstream fs(name, std::fstream::in | std::fstream::out);

  if (!fs)
    throw std::runtime_error("No file found with the name '" + name + "'.\n");

  try {
    this->parse(fs);
  } catch (const std::runtime_error& err) {
    std::cerr << "Error occurred in file parsing.\nError: " << err.what();
    return false;
  }

  fs.close();

  return true;
}
