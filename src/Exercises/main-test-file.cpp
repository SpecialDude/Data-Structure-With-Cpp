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

    std::cout << (3 << 2) << std::endl;

    printHeader("Exercise R-1.17 - AllKind class");
    std::cout << "Tests:" << std::endl;
    Exercise_1_8::AllKinds allKind(10, 259, 100.101f);
    std::cout << "Created a new Instance: AllKinds allKind(10, 259, 100.0f)" << ENDL;
    std::cout << "\tInt and Long sum: " << allKind.getIntLongSum() << ENDL;
    std::cout << "\tInt and Float sum: " << allKind.getIntFloatSum() << ENDL;
    std::cout << "\tLong and Float sum: " << allKind.getLongFloatSum() << ENDL;

    printFooter();
    

    return EXIT_SUCCESS;
}