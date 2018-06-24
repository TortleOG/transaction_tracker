#include <iostream>
#include <string>
#include <vector>

#include "transaction.h"
#include "menu.h"

int main() {
  tt::Menu menu { "WELCOME TO TRANSACTION TRACKER" };

  menu
    .add("View transactions")
    .add("Add transaction")
    .add("Remove last transaction")
    .add("View net gain/loss");

  menu.print();

  return 0;
}
