#ifndef GUARD_TRANSACTION_H
#define GUARD_TRANSACTION_H

#include <string>

namespace tt {

class Transaction {
  private:
    unsigned id;
    unsigned last_id;
    std::string name;
    double amount;
    std::string date_created;

  public:
    Transaction();
    Transaction(const unsigned&);
    Transaction(const unsigned&, const std::string&, const double&);
    Transaction(const unsigned&, const std::string&, const double&, const std::string&);

    // Getters
    int get_id() const { return id; }
    int get_last_id() const { return last_id; };
    std::string get_name() const { return name; };
    float get_amount() const { return amount; };
    std::string get_date() const { return date_created; };


    // Setters
    Transaction& set_id(const unsigned &i) { id = i; return *this; };
    Transaction& set_name(const std::string &s) { name = s; return *this; };
    Transaction& set_amount(const double &a) { amount = a; return *this; };
    Transaction& set_date(const std::string &d) { date_created = d; return *this; };

    // Methods
    void print();
};

} // namespace tt

std::ostream& operator<<(std::ostream&, const tt::Transaction&);
std::istream& operator>>(std::istream&, tt::Transaction&);

#endif
