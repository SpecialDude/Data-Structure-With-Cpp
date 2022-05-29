#include <iostream>
#include <vector>
#include "exercise1_8.h"

#define ENDL "\n"
#define EMPTY ""
#define ENDLT "\n\t"
#define ENDT "\t"

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
    printHeader("Exercise R-1.22 - Number of times a number can be divided by 2");
    std::cout << "Tests:" << ENDL;
    std::cout << "case 2.5: " << Exercise_1_8::divide_by_two(2.5) << ENDL;
    std::cout << "case 1.999: " << Exercise_1_8::divide_by_two(1.999) << ENDL;
    std::cout << "case 10.35: " << Exercise_1_8::divide_by_two(10.35) << ENDL;
    std::cout << "case 30.016: " << Exercise_1_8::divide_by_two(30.016) << ENDL;
    std::cout << "case 100.0: " << Exercise_1_8::divide_by_two(100.5) << ENDL;

    printFooter();
    
    // C-1.1 Test
    printHeader("Exercise C-1.1 - Reverse Array");
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
    printHeader("Exercise C-1.2 - Pair of numbers with even product");
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

    // C-1.3 Test
    printHeader("Exercise C-1.3 - Distinct Vector");
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

    // C-1.4 Test
    printHeader("Exercise C-1.4 - Print odd Elements only");
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

    // C-1.8
    printHeader("Exercise C-1.8 - Element by element product");
    std::cout << "Tests:" << ENDL;
    std::cout << "case\n\ta = ";
    std::vector<double> vectorA = {3.4, 49.04, 322.20, 39.102, 202.30};
    printArray(vectorA, vectorA.size(), ENDLT);
    std::cout << "b = ";
    std::vector<double> vectorB = {10.5, 7.98, 66.5, 90.2, 1.15};
    printArray(vectorB, vectorB.size(), ENDLT);
    std::cout << ": c = ";
    printArray(Exercise_1_8::element_by_element_product(vectorA, vectorB), vectorA.size(), ENDL);
    printFooter();

    // C-1.9
    printHeader("Exercise C-1.9 - Vector2 Operations");
    std::cout << "Test:" << ENDL;    
    std::cout << "\tCreating Vector2 Instance:\n";
    Exercise_1_8::Vector2 cordinateA(10, 47);
    Exercise_1_8::Vector2 cordinateB(16, -20);
    std::cout << ENDT << ENDT << "A = " << cordinateA << ", B = " << cordinateB << ENDL;
    std::cout << "\tPerforming operations:" << ENDL;
    std::cout << ENDT << ENDT << "A + B: " << cordinateA + cordinateB << ENDL;  // (rValues only, Destructor is called)
    std::cout << ENDT << ENDT << "A - B: " << cordinateA - cordinateB << ENDL;
    std::cout << ENDT << ENDT << "A * B: " << cordinateA * cordinateB << ENDL;
    std::cout << ENDT << ENDT << "A * 5: " << cordinateA * 5 << ENDL;
    std::cout << ENDT << ENDT << "10 * B: " << 10 * cordinateB << ENDL;
    printFooter();
    /* Exercise_1_8::Vector2 testv = 17 * cordinateB;  // (Rvalue: Copy and Assignment operator Constructors and Destructor NOT called)
    Exercise_1_8::Vector2 testv2;                   // (Calls the default constructor)

    std::cout << testv2 << ENDL;
    testv2 = 10 * cordinateB;                       // (Calls the Assignment operator, and Destructor for the Rvalue)
    std::cout << testv << ENDL;
    std::cout << testv2 << ENDL;
    printFooter();

    Exercise_1_8::Vector2 tobC = testv2;            // (Calls the Copy Constructor)
    Exercise_1_8::Vector2 testV3(testv);            // (Calls the copy Constructor)
    Exercise_1_8::Vector2 newTestV = testv2 = testv; // (Calls the Assignment operator, then the copy Constructor)
    printFooter(); */

    // C-1.10 Test
    printHeader("Exercise C-1.10 - Two to the power of i");
    std::cout << "Tests:" << ENDL;
    std::cout << "case 5: " << Exercise_1_8::two_to_power_of(5u) << ENDL;
    std::cout << "case 4: " << Exercise_1_8::two_to_power_of(4u) << ENDL;
    std::cout << "case 3: " << Exercise_1_8::two_to_power_of(3u) << ENDL;
    std::cout << "case 2: " << Exercise_1_8::two_to_power_of(2u) << ENDL;
    std::cout << "case 1: " << Exercise_1_8::two_to_power_of(1u) << ENDL;
    std::cout << "case 0: " << Exercise_1_8::two_to_power_of(0u) << ENDL;
    std::cout << "case -1: " << Exercise_1_8::two_to_power_of(-1) << ENDL;
    std::cout << "case -2: " << Exercise_1_8::two_to_power_of(-2) << ENDL;
    std::cout << "case -3: " << Exercise_1_8::two_to_power_of(-3) << ENDL;
    std::cout << "case -4: " << Exercise_1_8::two_to_power_of(-4) << ENDL;
    std::cout << "case -5: " << Exercise_1_8::two_to_power_of(-5) << ENDL;
    printFooter();

    // C-1.11 Test
    printHeader("Exercise C-1.11 - greatest_common_divisor(n, m)");
    std::cout << "Tests:" << ENDL;
    std::cout << "case 10, 5: " << Exercise_1_8::greatest_common_divisor(10, 5) << ENDL;
    std::cout << "case 13, 820: " << Exercise_1_8::greatest_common_divisor(13, 820) << ENDL;
    std::cout << "case 1024, 1000: " << Exercise_1_8::greatest_common_divisor(1024, 1000) << ENDL;
    std::cout << "case 773, 98: " << Exercise_1_8::greatest_common_divisor(773, 98) << ENDL;
    std::cout << "case 80844, 25320: " << Exercise_1_8::greatest_common_divisor(80844, 25320) << ENDL;
    printFooter();

    return EXIT_SUCCESS;
}