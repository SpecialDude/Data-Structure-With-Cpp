#include "numcpp.h"
#include <iostream>


int main()
{
    int arr[3] = {3, 2, 2};
    int array[12] = {6, -2, 23, 41, -5, 63, -7, 83, 9, 10, 11, 12};
    
    Numcpp::ndarray newArray(3, arr, array);

    std::cout << newArray << std::endl;

    newArray.reshape(2, new int[2]{4, 3});

    std::cout << "Reshaped!!\n" << std::endl;

    std::cout << newArray << std::endl;


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << i << ", " << j << " --> " << newArray.element_at(new int[2]{i, j}) << std::endl;
        }
    }
    std::cout << "length: " << newArray.length() << std::endl;


    std::cout << "Test: " << Numcpp::GeneralStuff::center("Tayo", 16, "##") << std::endl;

    Numcpp::ndarray updateVector = (2 * newArray);

    Numcpp::ndarray copyArray(updateVector);

    std::cout << &updateVector << std::endl;
    std::cout << &copyArray << std::endl;

    std::cout << updateVector << std::endl << std::endl;
    copyArray.reshape(3, new int[3]{2, 2, 3});
    std::cout << copyArray << std::endl << std::endl;

    Numcpp::ndarray* ptr;

    ptr = new Numcpp::ndarray(copyArray);

    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    delete ptr;

    std::cout << "Deleted the pointer variable" << std::endl;

    Numcpp::ndarray c = updateVector = copyArray;
    std::cout << "C address: " << &c << std::endl;
    std::cout << "uV address: " << &updateVector << std::endl;
    std::cout << "CA address: " << &copyArray << std::endl;

    std::cout << c << std::endl;
    c = c;

    return EXIT_SUCCESS;
}