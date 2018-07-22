#include <string>
#include <vector>
#include <iomanip>
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
      const auto oldp = std::cout.precision();
      std::cout << std::fixed << std::setprecision(2);

      for (auto& trn : trns) {
        std::cout << trn << '\n';
      }

      std::cout << std::defaultfloat << std::setprecision(oldp);
    })
    .add("Add transaction", [&]() {
      unsigned last_id = trns.back().get_id();

      tt::Transaction t { last_id };
      std::cin >> t;

      if (!std::cin.good())
        std::cin.clear();
      else
        trns.push_back(t);
    })
    .add("Remove last transaction", [&]() {
      if (trns.empty()) {
        std::cout << "There are no transactions to remove.\n";
        return;
      }

      std::cout << "Are you sure you want to remove this transaction? (y/n) ";
      char c;
      std::cin >> c;

      if (!std::cin.good())
        std::cin.clear();
      else if (c == 'y')
        trns.pop_back();
      else if (c != 'n')
        std::cout << "Error: Wrong input. The transaction will not be deleted.\n";
    })
    .add("View net gain/loss", []() {
      std::cout << "menu4\n";
    })
    .add("Exit");

  menu.print();

  std::cin >> menu;

  if (!std::cin.good())
    std::cin.clear();

  return 0;
}
