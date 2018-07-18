#include "menu.h"

#include <string>
#include <iostream>
#include <functional>

/**
 * Defualt Constructor
 */
tt::Menu::Menu() { }

/**
 * Creates a new menu object with a title and a defualt separator.
 * Constructor parameters:
 * -> title | string
 * Menu separator is defaulted to '='.
 */
tt::Menu::Menu(const std::string& title) {
  this->title = title;
  this->sep = std::string(title.size(), '=');
}

/**
 * Creates a new menu object with a title and a custom separator.
 * Parameters:
 * -> title | string
 * -> separator | char
 */
tt::Menu::Menu(const std::string& title, const char& sep) {
  this->title = title;
  this->sep = (title.size(), sep);
}

/**
 * Prints the menu to the output.
 * Returns void.
 */
void tt::Menu::print() {
  std::cout << this->title << '\n' << this->sep << '\n';

  for (const tt::menu_opt& op : this->opts) {
    std::cout << "(" << op.sel << ") " << op.name << '\n';
  }

  std::cout << this->sep << '\n';
}

/**
 * Adds a new item to the menu.
 *
 * First parameter is a string for the name of the item.
 * This item will appear as the following when Menu#print is called:
 * (a) Item Name
 * Returns a refernece to this class to allow method chaining.
 */
tt::Menu& tt::Menu::add(const std::string& name) {
  return this->add(name, nullptr);
}

/**
 * Adds a new item to the menu.
 *
 * First parameter is a string with the name of the item.
 * This item will apear as the following when Menu#print is called:
 * (a) Item Name
 *
 * Second parameter is a callback that will be called when this item is selected.
 * The callback takes no parameters and must return void.
 */
tt::Menu& tt::Menu::add(const std::string& name, const std::function<void()>& cb) {
  menu_opt opt { this->last_sel, name, cb };
  this->opts.push_back(opt);
  this->last_sel++;
  return *this;
}

std::istream& operator>>(std::istream& is, tt::Menu& menu) {
  char c;
  bool exit_state = false;
  while (!exit_state) {
    std::cout << "\nSelect a menu option: ";
    if (std::cin >> c) {
      for (const auto& opt : menu.get_opts()) {
        if (c == opt.sel && opt.cb) {
          std::cout << '\n' << opt.name << '\n' << menu.get_sep() << '\n';
          opt.cb();
        }
        else if (c == menu.get_opts().back().sel) {
          exit_state = true;
        }
      }
    }
  }

  return is;
}
