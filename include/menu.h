#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace tt {

struct menu_opt {
  char sel;
  std::string name;
  std::function<void()> cb;
};

class Menu {
  private:
    char csep;
    std::string sep;
    std::string title;
    char last_sel = 'a';
    std::vector<menu_opt> opts;

  public:
    Menu();
    Menu(const std::string&);
    Menu(const std::string&, const char&);

    // Getters
    char get_csep() const { return csep; }
    std::string get_sep() const { return sep; }
    std::string get_title() const { return title; }
    std::vector<menu_opt> get_opts() const { return opts; }

    // Setters
    Menu& set_csep(const char &c) { csep = c; return *this; }
    Menu& set_sep(const char &c) { sep = std::string(title.size(), c); return *this; }
    Menu& set_title(const std::string &t) { title = t; return *this; }

    // Methods
    void print();
    Menu& add(const std::string&);
    Menu& add(const std::string&, const std::function<void()>&);
};

} // namespace tt

std::istream& operator>>(std::istream& is, tt::Menu& menu);

#endif
