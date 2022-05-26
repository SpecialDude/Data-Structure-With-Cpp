#include <iostream>
#include "exercise1_8.h"

// R-1.7
int Exercise_1_8::sum_up_to_n(int n)
{
    return (n * (n - 1))/2 ;
}

// R-1.8
bool Exercise_1_8::isMultiple(long int n, long int m)
{
    return (n % m) == 0;
}

// R-1.9
void Exercise_1_8::printArray(int** A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << * ((*(A + i)) + j) << "    ";
        }
        std::cout << std::endl;        
    }
}

bool Exercise_1_8::CreditCard::chargeIt(double price)
{
    if (price < 0) return false;
    if (price + balance > double(limit)) return false;

    balance += price;
    return true;
}

void Exercise_1_8::CreditCard::makePayment(double payment)
{
    if (payment < 0) return;
    balance -= payment;
    double interest = payment * interest_rate;
    balance -= interest;
}

std::ostream& Exercise_1_8::operator<<(std::ostream& out, const Exercise_1_8::CreditCard& creditcard)
{
    out << "Credit Card" << std::endl;
    out << "\tNumber = " << creditcard.getNumber() << "\n";
    out << "\tName = " << creditcard.getName() << "\n";
    out << "\tBalance = " << creditcard.getBalance() << "\n";
    out << "\tLimit = " << creditcard.getLimit() << "\n";

    return out;
}
