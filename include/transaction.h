#ifndef GUARD_TRANSACTION_H
#define GUARD_TRANSACTION_H

#include <string>

namespace tt {

class Transaction {
  private:
    unsigned int id;
    std::string name;
    float amount;
    std::string date_created;

  public:
    Transaction(unsigned int, std::string, float);

    // Getters
    inline int get_id() const { return id; }
    inline std::string get_name() const { return name; }
    inline float get_amount() const { return amount; }
    inline std::string get_date() const { return date_created; }

    // Methods
    void print();
};

} // namespace tt

#endif
