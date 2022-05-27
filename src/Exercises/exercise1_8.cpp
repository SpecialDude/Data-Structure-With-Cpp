#include <iostream>
#include <vector>
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

// R-1.12 - R-1.16
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

// R-1.19
bool Exercise_1_8::isTwoPower(int i)
{
    return !(i == 0) && ((i & (i - 1)) == 0);
}

// R-1.21
int Exercise_1_8::sum_odd_up_to_n(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i += 2) sum += i;

    return sum;
}

// R-1.22
uint Exercise_1_8::divide_by_two(double x)
{
    uint times = 0;
    while (!(x < 2))
    {
        x /= 2;
        times++;
    }
    return times;
}

// C-1.1
void Exercise_1_8::reverse_array(int* arry, int size)
{
    int mid = size/2;

    for (int i = 0; i < mid; i++)
    {
        int temp = arry[i];
        int n = size - 1 - i;
        arry[i] = arry[n];
        arry[n] = temp;
    }
}

// C-1.2
bool Exercise_1_8::there_is_even_product(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((arr[i] * arr[j]) % 2 == 0) return 1;
        }
    }
    return 0;
}

// C-1.3
bool Exercise_1_8::they_are_distinct(std::vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j]) return 0;
        }
    }
    return 1;
}

// C-1.3
void Exercise_1_8::print_odd_only(std::vector<int> arr)
{
    std::cout << "[ ";

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 1) std::cout << arr[i] << " ";
    }
    std::cout << "]";
}

int testfunc()
{
    return 100;
}
