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

    /*
    C-1.5
    Write a C++ function that takes an array containing the set of all integers
    in the range 1 to 52 and shuffles it into random order. Use the built-in
    function rand, which returns a pseudo-random integer each time it is called.
    Your function should output each possible order with equal probability.
    */
    void shuffle_array(int* arr);

    /*
    C-1.6
    Write a short C++ program that outputs all possible strings formed by using
    each of the characters ’a’, ’b’, ’c’, ’d’, ’e’, and ’f’ exactly once.
    */
    void permuteSomeCharSet();

    /*
    C-1.7
    Write a short C++ program that takes all the lines input to standard input
    and writes them to standard output in reverse order. That is, each line is
    output in the correct order, but the ordering of the lines is reversed.
    */
    void reverse_line_inputs();

   /*
   C-1.8
   Write a short C++ program that takes two arguments of type STL vector<double>,
   a and b, and returns the element-by-element product of a and b. That is, it
   returns a vector c of the same length such that c[i] = a[i] · b[i].
   */
    std::vector<double> element_by_element_product(const std::vector<double>& a, const std::vector<double>& b);

    /*
    C-1.9
    Write a C++ class Vector2, that stores the (x, y) coordinates of a two-dimensional
    vector, where x and y are of type double. Show how to override various C++
    operators in order to implement the addition of twovectors (producing a vector result),
    the multiplication of a scalar times a vector (producing a vector result), and the dot
    product of two vectors (producing a double result).
    */
    class Vector2
    {
        private:
            double m_x;
            double m_y;
        
        public:
            Vector2() : m_x(0), m_y(0) {}
            Vector2(double x, double y) : m_x(x), m_y(y) {}
            // Vector2(const Vector2& other) : m_x(other.m_x), m_y(other.m_y) {std::cout << "Constructor: Copied!!!\n";}
            // ~Vector2() {std::cout << "Vector Destroyed\n";}
            // Vector2& operator=(const Vector2& other) {m_x = other.m_x; m_y = other.m_y; std::cout << "Operator Assignment (copying)\n"; return *this;}
            // void operator=(const Vector2& other) {m_x = other.m_x; m_y = other.m_y; std::cout << "Operator Assignment (copying)\n";}
            friend std::ostream& operator<<(std::ostream& out, const Vector2& vector2);
            friend Vector2 operator+(const Vector2& a, const Vector2& b);
            friend Vector2 operator-(const Vector2& a, const Vector2& b);
            friend double operator*(const Vector2& a, const Vector2& b);
            friend Vector2 operator*(const Vector2& vector2, double scalar);
    };
    std::ostream& operator<<(std::ostream& out, const Vector2& vector2);
    Vector2 operator+(const Vector2& a, const Vector2& b);
    Vector2 operator-(const Vector2& a, const Vector2& b);
    double operator*(const Vector2& a, const Vector2& b);
    Vector2 operator*(const Vector2& vector2, double scalar);
    Vector2 operator*(double scalar, const Vector2& vector2);

    /*
    Write an efficient C++ function that takes any integer value i and returns 2^i, as a
    long value. Your function should not multiply 2 by itself i times; there are much
    faster ways of computing 2i .
    */
    long two_to_power_of(unsigned int i);
    double two_to_power_of(signed int i);
    
    /*
    C-1.11
    The greatest common divisor, or GCD, of two positive integers n and m is the largest
    number j, such that n and m are both multiples of j. Euclid proposed a simple algorithm
    for computing GCD(n, m), where n > m, which is based on a concept known as the Chinese
    Remainder Theorem. The main idea of the algorithm is to repeatedly perform modulo computations
    of consecutive pairs of the sequence that starts (n, m, . . .), until reaching zero. The last
    nonzero number in this sequence is the GCD of n and m. For example, for n = 80, 844 and
    m = 25, 320, the sequence is as follows:
    */
    unsigned int greatest_common_divisor(unsigned int n, unsigned int m);

}

#endif