#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include <iostream>
#include <string>
#include <vector>

namespace tt {

struct menu_opt {
  char sel;
  std::string name;
};

class Menu {
  private:
    std::string sep;
    std::string title;
    char last_sel = 'a';
    std::vector<menu_opt> opts;

  public:
    Menu(const std::string&);
    Menu(const std::string&, const char&);

    // Getters
    inline std::string get_sep() const { return sep; }
    inline std::string get_title() const { return title; }
    inline std::vector<menu_opt> get_opts() const { return opts; }

    // Methods
    void print();
    Menu &add(const std::string&);
};

} // namespace tt

#endif
