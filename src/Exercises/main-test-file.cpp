#include <iostream>

namespace Exercise_1_8
{
    // R-1.7
    int sum_up_to_n(int n);

    // R-1.8
    bool isMultiple(long int n, long int m);

    // R-1.9
    void printArray(int** A, int m, int n);
}

int main()
{
    // R-1.7 Test
    std::cout << Exercise_1_8::sum_up_to_n(1) << std::endl;

    // R-1.8 Test
    std::cout << Exercise_1_8::isMultiple(7, 3) << std::endl;
    std::cout << Exercise_1_8::isMultiple(6, 3) << std::endl;
    
    int** arr = new int*[2]{new int[3]{3, 6, 3}, new int[3]{4, 6, 8}};

    Exercise_1_8::printArray(arr, 2, 3);

    return EXIT_SUCCESS;
}