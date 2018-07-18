#ifndef GUARD_LOADER_H
#define GUARD_LOADER_H

#include <string>
#include <vector>
#include <fstream>

#include "transaction.h"

namespace tt {

class Loader {
  private:
    std::vector<tt::Transaction> trns;

    // Methods
    void parse(std::fstream&);

  public:
    Loader();
    Loader(std::vector<tt::Transaction>&);

    // Getters
    std::vector<tt::Transaction> get_trns() const { return trns; };

    // Methods
    bool load_file(const std::string&);
};

} // namespace tt

#endif
