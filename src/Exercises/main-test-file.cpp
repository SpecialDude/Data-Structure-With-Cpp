#include <iostream>
#include <vector>
#include "exercise1_8.h"

#define ENDL "\n"

std::string operator*(const std::string& st, int times)
{
    std::string str = "";

    for (int i = 0; i < times; i++)
    {
        str += st;
    }

    return str;
}

void printHeader(const std::string strheader)
{
    std::cout << std::string("-") * (strheader.size() + 4) << std::endl;
    std::cout << "| " << strheader << " |" << std::endl;
    std::cout << std::string("-") * (strheader.size() + 4) << std::endl;
}

void printFooter()
{
    std::cout << std::string("-") * 40 << "\n\n" << std::endl;
}

template<typename T>
void printArray(T* arr, int size, std::string end = ENDL)
{
    std::cout << "[";
    for (int i = 0; i < size-1; i++)
    {
        std::cout << *(int*)((char*)arr + (sizeof(T) * i)) << ", ";
    }
    std::cout << *(int*)((char*)arr + (sizeof(T) * (size - 1))) << "]" << end;
}

template<typename T>
void printArray(T arr, int size, std::string end = ENDL)
{
    std::cout << "[";
    for (int i = 0; i < size-1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[size - 1] << "]" << end;
}

void TayoManipulatingPointers()
{
    int arr[5] = {1, 2, 4, 4, 6};
    int* ptr = arr;
    std::cout << "arr: " << arr << ENDL;
    std::cout << "&arr: " << &arr << ENDL;
    std::cout << "ptr: " << ptr << ENDL;
    std::cout << "&ptr: " << &ptr << ENDL;
    std::cout << "(int**)ptr: " << (int**)ptr << ENDL;
    std::cout << "(int*)&ptr: " << (int*)&ptr << ENDL;
    std::cout << "ptr - &ptr: " << ((int**)ptr - (&ptr)) << ENDL;
    std::cout << "ptr - &ptr: " << (ptr - (int*)(&ptr)) << ENDL;
    
    std::cout << ": " << *(((int*)(&ptr)) + 2) << ENDL;

    std::cout << sizeof(int*) << ENDL;
    std::cout << sizeof(int**) << ENDL;

    printFooter();
    std::cout << ptr + 19 << ENDL;
    std::cout << *(ptr + 19) << ENDL;
    *(const char**)(ptr + 19) = "Adetayo";
    std::cout << *(char**)(ptr + 19) << ENDL;
    printFooter();

    std::cout << ptr + 40 << ENDL;
    std::cout << *(ptr + 40) << ENDL;
    *(Exercise_1_8::CreditCard**)(ptr + 40) = new Exercise_1_8::CreditCard("Tayo", "Emmanuel", 30); 


    std::cout << **(Exercise_1_8::CreditCard**)(ptr + 40) << ENDL;

    // std::cout << sizeof(char) << std::endl; // -- > 1byte
}

int main()
{
    // R-1.7 Test
    printHeader("Exercise R-1.7 - Summing up to N-1");
    std::cout << "Tests:" << std::endl;
    std::cout << "\t" << "Case 4 (Summing up to 3): " << Exercise_1_8::sum_up_to_n(4) << std::endl;
    std::cout << "\t" << "Case 15 (Summing up to 14): " << Exercise_1_8::sum_up_to_n(15) << std::endl;
    std::cout << "\t" << "Case 101 (Summing up to 100): " << Exercise_1_8::sum_up_to_n(101) << std::endl;
    printFooter();

    // R-1.8 Test
    printHeader("Exercise R-1.8 - isMultiple(n, m), (is n a multiple of m)");
    std::cout << "Tests:" << std::endl;
    std::cout << "\t" << "Case isMultiple(7, 3): " << Exercise_1_8::isMultiple(7, 3) << std::endl;
    std::cout << "\t" << "Case isMultiple(6, 3): " << Exercise_1_8::isMultiple(6, 3) << std::endl;
    std::cout << "\t" << "Case isMultiple(1024, 8): " << Exercise_1_8::isMultiple(1024, 8) << std::endl;
    printFooter();

    // R-1.9 Test
    printHeader("Exercise R-1.9 - Print a Two Dimensional Array");
    std::cout << "Tests:" << std::endl;
    int** testArrayA = new int*[2]{new int[3]{3, 6, 3}, new int[3]{4, 6, 8}};
    int** testArrayB = new int*[3]{
        new int[3]{100, -59, 246},
        new int[3]{-15, 109, 450},
        new int[3]{-43, -11, -99}
        };
    std::cout << "Case 2x3 Array" << std::endl;
    Exercise_1_8::printArray(testArrayA, 2, 3);
    std::cout << std::endl;

    std::cout << "Case 3x3 Array" << std::endl;
    Exercise_1_8::printArray(testArrayB, 3, 3);
    delete[] testArrayA;
    delete[] testArrayB;
    printFooter();

    // R-1.11 Test
    printHeader("Exercise R-1.11 - C++ class Flower");
    std::cout << "Tests:" << std::endl;
    std::cout << "Create new Flower instance" << std::endl;
    Exercise_1_8::Flower* cflower = new Exercise_1_8::Flower("Cauli", 5, 100.0);
    std::cout << "Printing Initial Values:" << std::endl;
    std::cout << "\t" << "Flower Name: " << cflower->name() << std::endl;
    std::cout << "\t" << "Flower Pedals: " << cflower->pedals() << std::endl;
    std::cout << "\t" << "Flower Price: " << cflower->price() << std::endl;
    std::cout << "Changing the data of instance using the setter methods" << std::endl;
    cflower->setname("Rose");
    cflower->setpedals(10);
    cflower->setprice(200.0);
    std::cout << "Printing New Values:" << std::endl;
    std::cout << "\t" << "Flower Name: " << cflower->name() << std::endl;
    std::cout << "\t" << "Flower Pedals: " << cflower->pedals() << std::endl;
    std::cout << "\t" << "Flower Price: " << cflower->price() << std::endl;

    delete cflower;
    printFooter();

    // R-1.12 Test
    printHeader("Exercise R-1.12 - CreditCard class");
    std::cout << "Tests:" << std::endl;
    Exercise_1_8::CreditCard* wallet[10];

    wallet[0] = new Exercise_1_8::CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
    wallet[1] = new Exercise_1_8::CreditCard("3485 0399 3395 5309", "Clifford Devoe", 3500);
    wallet[2] = new Exercise_1_8::CreditCard("6011 0375 3294 2994", "Barry Allen", 5000);
   
    std::cout << "Crediting Balance" << std::endl;
    for (int j = 1; j < 16; j++)
    {
        wallet[0]->chargeIt(double(j));
        wallet[1]->chargeIt(double(2 * j));
        wallet[2]->chargeIt(double(3 * j));
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout << *wallet[i];
    }
    
    printFooter();

    // R-1.17 Test
    printHeader("Exercise R-1.17 - AllKind class");
    std::cout << "Tests:" << ENDL;
    Exercise_1_8::AllKinds allKind(10, 259, 100.101f);
    std::cout << "Created a new Instance: AllKinds allKind(10, 259, 100.0f)" << ENDL;
    std::cout << "\tInt and Long sum: " << allKind.getIntLongSum() << ENDL;
    std::cout << "\tInt and Float sum: " << allKind.getIntFloatSum() << ENDL;
    std::cout << "\tLong and Float sum: " << allKind.getLongFloatSum() << ENDL;

    printFooter();

    // R-1.19 Test
    printHeader("Exercise R-1.19 - isTwoPower(i), (is i a power of 2)");
    std::cout << "Tests:" << ENDL;
    std::cout << "case 0: " << Exercise_1_8::isTwoPower(0) << ENDL;
    std::cout << "case 1: " << Exercise_1_8::isTwoPower(1) << ENDL;
    std::cout << "case 2: " << Exercise_1_8::isTwoPower(2) << ENDL;
    std::cout << "case 8: " << Exercise_1_8::isTwoPower(8) << ENDL;
    std::cout << "case 63: " << Exercise_1_8::isTwoPower(63) << ENDL;
    std::cout << "case 64: " << Exercise_1_8::isTwoPower(64) << ENDL;
    std::cout << "case 100: " << Exercise_1_8::isTwoPower(100) << ENDL;
    std::cout << "case 512: " << Exercise_1_8::isTwoPower(512) << ENDL;

    printFooter();

    // R-1.21 Test
    printHeader("Exercise R-1.21 - Sum odd integers up to n");
    std::cout << "Tests:" << ENDL;
    std::cout << "case 0: " << Exercise_1_8::sum_odd_up_to_n(0) << ENDL;
    std::cout << "case 1: " << Exercise_1_8::sum_odd_up_to_n(1) << ENDL;
    std::cout << "case 8: " << Exercise_1_8::sum_odd_up_to_n(8) << ENDL;
    std::cout << "case 10: " << Exercise_1_8::sum_odd_up_to_n(10) << ENDL;
    std::cout << "case 63: " << Exercise_1_8::sum_odd_up_to_n(63) << ENDL;
    std::cout << "case 64: " << Exercise_1_8::sum_odd_up_to_n(64) << ENDL;
    std::cout << "case 100: " << Exercise_1_8::sum_odd_up_to_n(100) << ENDL;
    std::cout << "case 512: " << Exercise_1_8::sum_odd_up_to_n(512) << ENDL;

    printFooter();

    // R-1.22 Test
    printHeader("Exercice R-1.22 - Number of times a number can be divided by 2");
    std::cout << "Tests:" << ENDL;
    std::cout << "case 2.5: " << Exercise_1_8::divide_by_two(2.5) << ENDL;
    std::cout << "case 1.999: " << Exercise_1_8::divide_by_two(1.999) << ENDL;
    std::cout << "case 10.35: " << Exercise_1_8::divide_by_two(10.35) << ENDL;
    std::cout << "case 30.016: " << Exercise_1_8::divide_by_two(30.016) << ENDL;
    std::cout << "case 100.0: " << Exercise_1_8::divide_by_two(100.5) << ENDL;

    printFooter();
    
    // C-1.1 Test
    printHeader("Exercice C-1.1 - Reverse Array");
    std::cout << "Tests:" << ENDL;
    std::cout << "case ";
    int arr[5] = {1, 2, 3, 4, 5};
    printArray<int>(arr, 5, "");
    std::cout << ": ";
    Exercise_1_8::reverse_array(arr, 5);
    printArray<int>(arr, 5, ENDL);

    std::cout << "case ";
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray<int>(arr2, 10, "");
    std::cout << ": ";
    Exercise_1_8::reverse_array(arr2, 10);
    printArray<int>(arr2, 10, ENDL);

    printFooter();
    

    // C-1.2 Test
    printHeader("Exercice C-1.2 - Pair of numbers with even product");
    std::cout << "Tests:" << ENDL;
    std::cout << "case ";
    int testarr[5] = {1, 2, 3, 4, 5};
    printArray<int>(testarr, 5, "");
    std::cout << ": " << Exercise_1_8::there_is_even_product(testarr, 5) << ENDL;

    std::cout << "case ";
    int testarr2[7] = {3, 15, 5, 1, 7, 9, 11};
    printArray<int>(testarr2, 7, "");
    std::cout << ": " << Exercise_1_8::there_is_even_product(testarr2, 7) << ENDL;

    printFooter();

    // C-1.2 Test
    printHeader("Exercice C-1.2 - Distinct Vector");
    std::cout << "Tests:" << ENDL;
    std::cout << "case ";
    std::vector<int> vect1;
    vect1.reserve(8);
    vect1 = {1, 5, 8, 9, 0, 3, 5, 4};
    printArray<std::vector<int>>(vect1, vect1.size(), "");
    std::cout << ": " << Exercise_1_8::they_are_distinct(vect1) << ENDL;

    std::cout << "case ";
    std::vector<int> vect2;
    vect2.reserve(6);
    vect2 = {1, 5, 8, 9, 0, 4};
    printArray<std::vector<int>>(vect2, vect2.size(), "");
    std::cout << ": " << Exercise_1_8::they_are_distinct(vect2) << ENDL;

    printFooter();

    // C-1.3 Test
    printHeader("Exercice C-1.2 - Print odd Elements only");
    std::cout << "Tests:" << ENDL;
    std::cout << "case ";
    printArray<std::vector<int>>(vect2, vect2.size(), "");
    std::cout << ": ";
    Exercise_1_8::print_odd_only(vect2);
    std::cout << ENDL;

    std::cout << "case ";
    printArray<std::vector<int>>(vect1, vect1.size(), "");
    std::cout << ": ";
    Exercise_1_8::print_odd_only(vect1);
    std::cout << ENDL;

    printFooter();

    return EXIT_SUCCESS;
}