#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>

class Book
{
public:
    Book( const std::string &author, const std::string &name);
    void print() const;
    void loan(Date const &date);
    void renew();
    void give_back();

private:
    std::string author_;
    std::string name_;
    Date loan_date_;
    Date return_date_;
    bool available_;


};

#endif // BOOK_HH

