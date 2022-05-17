#include <iostream>
namespace Exercise_1_8
{
    // Reinforcement R-1.7
    /* Write a short C++ function that takes an integer n and return the sum
    of all the integers smaller than n. */
    int sum_up_to_n(int n)
    {
        return (n * (n - 1))/2 ;
    }

    // R-1.8
    /* Write a short C++ function, isMultiple, that takes two positive long value,
    n and m, and return true if and only if n is a multiple of m, that is, 
    n = mi for some integer i. */
    bool isMultiple(long int n, long int m)
    {
        return (n % m) == 0;
    }

    // R-1.9
    /* Write a C++ function printArray(A, m, n) that prints an m x n two dimensional
    array A of integers, declared to be int** A, to the standard out. Each of the
    m rows should appear on a separate line. */
    void printArray(int** A, int m, int n)
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

    // R-1.11
    /* Write a C++ class, Flower, that has three members variables of type string,
    int and float, which respectively represent the name of the flower, its 
    number of pedals, and price. Your class must include a constructor method
    that initializes each variable to an appropriate value, and your class should
    include functions for setting the value of each type and getting the value of 
    each type. */
    class Flower
    {
        private:
            std::string name;
            int number_of_pedals;
            float price;

        public:
            Flower(std::string& nm, int pedals, float p) : name(nm), number_of_pedals(pedals), price(p){}
            
    };
}