#include <string>
#include <vector>
#include <fstream>

#include "menu.h"
#include "loader.h"
#include "transaction.h"

int main() {
  std::vector<tt::Transaction> trns;
  tt::Loader loader { trns };

  std::cout << "Loading transactions...\n";

  try {
    if (!loader.load_file("./bin/example.txt")) {
      return -1;
    }
  } catch (const std::runtime_error& err) {
    std::cerr << "It seems an error has occured!\nError: " << err.what();
    return -1;
  }

  trns = loader.get_trns();

  tt::Menu menu { "WELCOME TO TRANSACTION TRACKER" };

  menu
    .add("View transactions", [&]() {
      std::cout << "ID | NAME | AMOUNT | DATE\n";
      for (const auto& trn : trns) {
        std::cout << trn << "\n";
      }
    })
    .add("Add transaction", [&]() {
      unsigned int last_id = trns.back().get_id();
      tt::Transaction t { last_id };
      std::cin >> t;
      trns.push_back(t);
    })
    .add("Remove last transaction", [&]() {
      std::cout << "Are you sure you want to remove this transaction? (y/n) ";
      char c;
      std::cin >> c;
      if (c == 'y') trns.pop_back();
      else if (c != 'n') std::cout << "Error: Wrong input. The transaction will not be deleted.\n";
    })
    .add("View net gain/loss", []() {
      std::cout << "menu4\n";
    })
    .add("Exit");

  menu.print();

  std::cin >> menu;

  return 0;
}
