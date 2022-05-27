#ifndef _EXERCISE1_8_H
#define _EXERCISE1_8_H

#include <iostream>
namespace Exercise_1_8
{
    /* Reinforcement R-1.7
    Write a short C++ function that takes an integer n and return the sum
    of all the integers smaller than n. */
    int sum_up_to_n(int n);

    /* R-1.8
    Write a short C++ function, isMultiple, that takes two positive long value,
    n and m, and return true if and only if n is a multiple of m, that is, 
    n = mi for some integer i. */
    bool isMultiple(long int n, long int m);

    /* R-1.9
    Write a C++ function printArray(A, m, n) that prints an m x n two dimensional
    array A of integers, declared to be int** A, to the standard out. Each of the
    m rows should appear on a separate line. */
    void printArray(int** A, int m, int n);

    /* R-1.11
    Write a C++ class, Flower, that has three members variables of type string,
    int and float, which respectively represent the name of the flower, its 
    number of pedals, and price. Your class must include a constructor method
    that initializes each variable to an appropriate value, and your class should
    include functions for setting the value of each type and getting the value of 
    each type. */
    class Flower
    {
        private:
            std::string m_name;
            int m_number_of_pedals;
            float m_price;

        public:
            Flower(const std::string& nm, int pedals, float p) : 
                m_name(nm),
                m_number_of_pedals(pedals),
                m_price(p)
                {}
            std::string name() const {return m_name;}
            int pedals() const {return m_number_of_pedals;}
            float price() const {return m_price;}

            void setname(const std::string& name) {m_name = name;}
            void setpedals(int pedals) {m_number_of_pedals = pedals;}
            void setprice(float price) {m_price = price;}            
    };

    /*
    R-1.12 - R-1.16
    Modifying the CreditCard class
    1. Check for negative numbers when making payments and crediting balance
    2. Charge interest on every payment
    3. Charge interest on late payments 
    */
    class CreditCard
    {
        private:
            std::string number;
            std::string name;
            int limit;
            double balance;
            float interest_rate;
        
        public:
            CreditCard(
                const std::string& no,
                const std::string& nm,
                int lim,
                double bal=0,
                float interest=0.1f
            ) : number(no), name(nm), limit(lim), balance(bal), interest_rate(interest) {}
            std::string getNumber() const {return number;}
            std::string getName() const {return name;}
            double getBalance() const {return balance;}
            int getLimit() const {return limit;}

            bool chargeIt(double price);
            void makePayment(double payment);

    };
    std::ostream& operator<<(std::ostream& out, const CreditCard& creditcard);

    /*
    R-1.17
    Write a C++ class, AllKinds, that has three members variables ot type int. 
    long and float, respectively. Each class must include a constructor function 
    that initializes each variable to a nonzero value, and each class should include 
    functions for setting the value of each type, getting the value of each type, and 
    computing and returning the sum of each possible combination of types.
    */
    class AllKinds
    {
        private:
            int m_var1;
            long m_var2;
            float m_var3;

        public:
            AllKinds(int kind1, long kind2, float kind3): m_var1(kind1), m_var2(kind2), m_var3(kind3) {}
            int getIntVar() const {return m_var1;}
            long getLongVar() const {return m_var2;}
            float getFloatVar() const {return m_var3;}

            void setIntVar(int newInt) {m_var1 = newInt;}
            void setLongVar(long newLong) {m_var2 = newLong;}
            void setFloatVar(float newFloat) {m_var3 = newFloat;}

            long getIntLongSum() {return m_var1 + m_var2;}
            float getLongFloatSum() {return m_var2 + m_var3;}
            float getIntFloatSum() {return m_var1 + m_var3;}
            float getAllSum() {return m_var2 + m_var2 + m_var3;}
    };

    /*
    R-1.18
    Write a short C++ function, isMultiple, that takes two long values, n and
    m, and returns true if and only if n is a multiple of m, that is, n = m · i for
    some integer i.
    Implemented!! (Check exercise R-1.8)
    */

    /*
    R-1.19
    Write a short C++ function, isTwoPower, that takes an int i and returns true
    if and only if i is a power of 2. Do not use multiplication or division however.
    */
    bool isTwoPower(int i);

    /*
    R-1.20
    Write a short C++ function that takes an integer n and returns the sum of all the
    integers smaller than n
    Implemented!! (Check exercise R-1.7)
    */

    /*
    R-1.21
    Write a short C++ function that takes an integer n and returns the sum of all the
    odd integers smaller than n
    Implemented!! (Check exercise R-1.7)
    */
    int sum_odd_up_to_n(int n);

    /*
    R-1.22
    Write a short C++ function that takes a positive double value x and returns the number
    of times we can divide x by 2 before we get a number less than 2
    */
    uint divide_by_two(double x);

    /*
    Creativity C-1.1
    Reverse Array
    */
    void reverse_array(int* arry, int size);
    
    /*
    C-1.2
    Write a short C++ function that takes an array of int values and determines
    if there is a pair of numbers in the array whose product is even.
    */
    bool there_is_even_product(int* arr, int size);

    /*
    C-1.3
    Write a C++ function that takes an STL vector of int values and determines
    if all the numbers are different from each other (that is, they are distinct).
    */
    bool they_are_distinct(std::vector<int> arr);

    /*
    C-1.4
    Write a C++ function that takes an STL vector of int values and prints all
    the odd values in the vector.
    */
    void print_odd_only(std::vector<int> arr);
}

int testfunc();

#endif