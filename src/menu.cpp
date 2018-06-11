#include "menu.h"

#include <string>
#include <iostream>

tt::Menu::Menu(std::string title) {
  this->title = title;
  this->sep = std::string(title.size(), '=');
}

tt::Menu::Menu(std::string title, char sep) {
  this->title = title;
  this->sep = (title.size(), sep);
}

void tt::Menu::print() {
  std::cout << this->title + '\n' + this->sep + '\n';

  for (const tt::menu_opt& op : this->opts) {
    std::cout << "(" << op.sel << ") " << op.name << '\n';
  }

  std::cout << this->sep << '\n';
}

tt::Menu &tt::Menu::add(const std::string& name) {
  menu_opt opt { this->last_sel, name };
  this->opts.push_back(opt);
  this->last_sel++;
  return *this;
}
