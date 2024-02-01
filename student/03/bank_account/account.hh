#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    // Constructor
    Account(const std::string& owner, bool has_credit = false);
    //method to print the mney
    void print() const;

    //Method to save money
    void save_money(int amount);

    //Method to take money
    void take_money(int amount);

    //Method to trnasfer money
    void transfer_to(Account &account, int amount);

    //Mrthod to set credit
    void set_credit_limit(int limit);



    // More methods

private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban();
    bool check_money_transfer(int amount);

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;

    // More attributes/methods
    std::string iban_;
    std::string owner_;
    int balance_;
    int credit_limit_;
    bool has_credit_;




};


#endif // ACCOUNT_HH



