#include <cstdlib>
#include <iostream>
#include <math.h>
#include <filesystem>
#include <array>
#include <mat.h>

using namespace NDarray;
// my defined namepace

namespace SpanishStuff
{
    // global types
    enum SpanishMonth {
        ENERO, FEBRERO, MARZO, ABRIL,
        MAYO, JUNIO, JULIO, AGOSTO,
        SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
    };
    enum SpanishDay {
        LUNES = 1,
        MARTEZ = 2,
        MIERCOLES = 3,
        JUEVES = 4,
        VIERNEZ = 5,
        SABADO = 6,
        DOMINGO = 0
    };
    enum SpanishPronouns {
        Yo, Tu, El, Ella, Usted, Nosotros, Vosotros, Vos = 6, Ellos, Ellas, Ustedes
    }; // Pronouns (Singular and Plural)

    const int N_Pronouns = 11;
    std::string pronounMaps[N_Pronouns] = {
        "Yo",       "Tu",               "El",       "Ella",     "Usted",
        "Nosotros", "Vosotros", "Vos",  "Ellos",    "Ellas",    "Ustedes"
    };

    std::string endingAR[] = { "o", "as", "a", "amos", "ais", "an"}; // AR Verbs
    std::string endingER[] = { "o", "es", "e", "emos", "eis", "en"}; // ER Verbs
    std::string SERconjugate[] = {"soy", "eres", "es", "somos", "seis", "son"}; // SER (To Be)
    std::string ESTARconjugate[] = {"estoy", "estas", "esta", "estamos", "estais", "estan"}; // ESTAR (To Be)
    std::string IRconjugate[] = {"voy", "vas", "va", "vamos", "vais", "van"}; // IR (To Go)

    // Type Definitions
    typedef std::string SpanishVerb;
    typedef std::string SpanishPronoun;
}



namespace GeneralStuff
{
    struct Inform {
        SpanishStuff::SpanishDay day;
        std::string details;
        int number;

        std::ostream& operator<<(std::ostream& out)
        {
            out << "Inform(\n\tDay: " << day << "\n\tDetails: " << details << "\n\tNumber: " << number << std::endl;
            return out;
        };
    };

    struct Vector {
        int x;
        int y;

        bool operator==(const Vector& other)
        {
            return x == other.x && y == other.y;
        };

        Vector operator+(const Vector& other)
        {
            return {x + other.x, y + other.y};
        }
        
        Vector operator-(const Vector& other)
        {
            return {x - other.x, y - other.y};
        }

        int operator*(const Vector& other)
        {
            return (x * other.x) + (y * other.y);
        }
    };

    class Counter
    {
        public:
            Counter();
            int getCount();
            void increaseBy(int n);
        
        private:
            int count;
    };

    Counter::Counter()      // Contructor
    {
        count = 0;
    }

    int Counter::getCount()
    {
        return count;
    }

    void Counter::increaseBy(int n)
    {
        count += n;
    }

    class Matrix
    {
        int rsize;
        int csize;
        int size;
        int* matrix;

        //std::array<std::array<int, 5>, 5> matrix;

        public:
            Matrix();
            // Matrix(int size);
            // Matrix(int row, int column);
            Matrix(int* m, int rowsize, int columnsize);
            // ~Matrix();
            // void copy();
            std::ostream& operator<<(std::ostream& out);
            int getelement(int i, int j);
            int getsize();
            int rowsize();
            int columnsize();
            int getravelelement(int i);

        
    };

    // Creates a 3x3 Identity Matrix
    Matrix::Matrix()
    {
        rsize = 3;
        csize = 3;
        size = rsize * csize;
        matrix = new int[size];

        int m = 0;
        int n = 0;
        for (int i = 0; i < size; i++)
        {
            if (m == n)
            {
                matrix[i] = 1;
            }
            else
            {
                matrix[i] = 0;
            }


            n++;
            if (n == csize)
            {
                n = 0;
                m++;
            }
        }
    }

    Matrix::Matrix(int* m, int rowsize, int columnsize)
    {
        rsize = rowsize;
        csize = columnsize;
        size = rsize * csize;

        matrix = new int[size];

        for (int i = 0; i < size; i++)
        {
            matrix[i] = m[i];
        }
    }

    std::ostream& Matrix::operator<<(std::ostream& out)
    {
        int c =  1;
        for (int i = 0; i < size; i++)
        {
            out << matrix[i] << "\t";
            
            if (c == csize)
            {
                out << "\n";
                c = 1;
            }
            c++;
        }
        return out;
    }

    int Matrix::getelement(int i, int j)
    {
        // int k = 0;

        // for (int m = 0; m < rsize; m++)
        // {
        //     for (int n = 0; n < csize; n++)
        //     {
                
        //         if (m == i and n == j)
        //         {
        //             return matrix[k];
        //         }    
        //         k++;
        //     }
        // }

        // return matrix[k];

        return matrix[i * csize + j];
    }

    int Matrix::getravelelement(int i)
    {
        return matrix[i];
    }

    int Matrix::rowsize()
    {
        return rsize;
    }

    int Matrix::columnsize()
    {
        return csize;
    }

    int Matrix::getsize()
    {
        return size;
    }


}

using namespace SpanishStuff;
using namespace GeneralStuff;

// Prototyping
std::string toBool(int x);
void compareScore(int n, int* a, int* b, int* result);
void printArray(int* array, int size);
std::string dayTOString(SpanishDay day);
SpanishVerb conjugate(SpanishVerb verb);
std::string toTitle(std::string text);
std::string toUpper(std::string text);
std::string toLower(std::string text);
std::string toString(int value, std::string *map);
void doSomethingWith(int objectA, int& objectB);
void doSomethingWith(int* objectA, int* objectB);
void printVector(const Vector& vector);

bool operator==(const Inform& informOne, const Inform& informTwo)
{
    return informOne.details == informTwo.details;
}

std::ostream& operator<<(std::ostream& out, const Inform& inform)
{
    out << "Inform(\n\tDay: " << dayTOString(inform.day) << "\n\tDetails: " << inform.details << "\n\tNumber: " << inform.number << "\n)" << std::endl;
    return out;
}


std::ostream& operator<<(std::ostream& out, Matrix& matrix)
{
    // out << "Repr" << std::endl;
    // for (int i = 0; i < matrix.rowsize() ; i++)
    // {
    //     for (int j = 0; j < (matrix.columnsize()); j++)
    //     {
    //         out << matrix.getelement(i, j) << "\t";
    //     }
    //     out << "\n";
    // }

    // out << std::endl;
    // return out;

    int c =  1;
    for (int i = 0; i < matrix.getsize(); i++)
    {
        out << matrix.getravelelement(i) << "\t";        
        
        if (c == matrix.columnsize())
        {
            out << "\n";
            c = 0;
        }
        c++;
        
    }
    return out;
}

inline int min(int a, int b) {return (a < b ? a : b);}

int main()
{
    std::cout << "Data Structure with C++" << std::endl;

    // Primitive Data Type
    // byte, short, int, long int, float, double
    // char

    char letterA = 'A';

    std::cout << "The integer value of letter '" << letterA << "' is " << int(letterA) << std::endl;

    int i = 0;

    while (i < 257)
    {
        std::cout << i << " --> " << (char)i++ << std::endl;
    }

    // Pointers
    int a = 10;

    int* pointer = &a;

    std::cout << pointer << std::endl;    // prints the location address of the variable a
    std::cout << &pointer << std::endl;   // prints the location address of the pointer variable
    std::cout << **&pointer << std::endl; // prints the content of the dereferenced address

    // Enumeration

    SpanishMonth myMonth = JULIO;

    std::cout << "My birthmonth is the " << myMonth << "th of the Year" << std::endl;

    SpanishDay day = LUNES;
       

    std::cout << toBool(day == LUNES) << std::endl;
    std::cout << toBool(day == MARTEZ) << std:: endl;
    std::cout << day << std::endl;
    dayTOString(day);
    
    // Arrays and Pointers

    int* pointArray[6];

    std::cout << *(pointArray) << std::endl;

    char myC[] = {'t', 'a', 'y', 'o'};

    char* t = myC;
    char* a2 = &myC[1];
    char* t2 = &myC[0];
    
    std::cout << t << std::endl;
    std::cout << *a2 << std::endl;
    std::cout << *t2 << std::endl;
    std::cout << myC << std::endl;


    printf("\nWorking with Arrays\n");
    
    int k[5] = {4, 6, 7, 8, 10};
    printArray(k, 5);

    int result[2];
    int alex[] = {4, 5, 33, 0};
    int bob[] = {8, 9, 89, 9};

    compareScore(4, alex, bob, result);
    printArray(result, 2);

    
    // STL Strings and C-style string
    printf("\nSTL String and C-Style String\n");
    std::string myName = "Adetayo";

    std::cout << myName << std::endl;
    std::cout << "Length: " << myName.size() << std::endl;

    const char* name  = myName.c_str();

    printf(name);


    // Structure (Struct)
    printf("\nStructure (struct)\n");
    

    Inform m = {LUNES, "Test", 7};
    std::cout << dayTOString(m.day) << std::endl;

    // accesing struct members data with the arrow notation
    // pointer to a struc

    Inform *p;

    p = new Inform;

    p->day = MARTEZ;
    p->details = "This a struct pointer";
    p->number = 100;

    std::cout << "\nNew Struc Data: Inform" << std::endl;
    std::cout << "Day: " << dayTOString(p->day) << std::endl;
    std::cout << "Details: " << p->details << std::endl;
    std::cout << "Number: " << p->number << std::endl;

    // No automatic Garbage collection for dynamically created object
    // Always remember to remove them

    delete p;

    // dynamic allocation with arrays
    char *arr = new char[500];
    arr[3] = '4';
    arr[0] = 'a';
    arr[2] = 'm';
    std::cout << "\nDynamic Allocation (Arrays)" << std::endl;
    std::cout << arr[2] << arr[0] << arr[3] << std::endl;
    delete [] arr;

    std::cout << "\n\n" << std::endl;

    // Reference

    std::string myNameA = "Adetayo";

    std::string& myAlias = myNameA;

    myAlias += " Adeoti";

    std::cout << "My name: " << myNameA << std::endl;
    std::cout << "Reference: " << myAlias << std::endl;


    // Named Constants, Scope, and Namespaces
    // Constants (const)
    // Enumeration (enum)
    // Typedef (typedef)

    const int N_DAYS = 7;
    const int N_WEEKS = 4;
    const int N_MONTHS = N_DAYS * N_WEEKS;

    

    SpanishVerb tobeA = "SER";
    SpanishVerb tobeB = "ESTAR";
    SpanishVerb togo = "IR";
    SpanishVerb tospeak = "HABLAR";

    std::cout << toString(Yo, pronounMaps) << std::endl;

    conjugate(tospeak);

    // Casting types
    // C-sytle traditional casting
    // C++ functional casting
    // Explicit casting
    //      static_cast
    //      dynamic_cast
    //      const_cast
    //      reinterprete_cast
    std::cout << "\n\nCasting Types" << std::endl;
    a = 100;
    int b = 99;

    std::cout << a/b << std::endl;
    std::cout << double(a) / b << std::endl;
    std::cout << (double)a / (double)b << std::endl;
    std::cout << static_cast<int>(100.32323) << std::endl;

    // Control Flow
    // if, else if, else, switch
    // But I ain't doing it here, I know this already
    // On Second thought, Lemme just do for switch
    std::cout << "\n\nControl Flow (switch)" << std::endl;

    // SpanishDay day = LUNES;
    day = SABADO;

    switch (day)
    {
    case LUNES:
        printf("It is Monday");
        break;
    
    case MARTEZ:
        printf("Okay, today is Tuesday");
        break;

    default:
        printf("Nah, its not Monday or Tuesday");
        break;
    }

    // Conditional loop 
    //      do while loop
    //      while loop
    std::cout << "\n\nConditional Loops (while, do while)" << std::endl;
    int noiseArr[100];
    int counter = 0;
    long long sum = 0;
    
    while (counter < 100 && noiseArr[counter] >= 0)
    {
        std::cout << noiseArr[counter] << std::endl;
        sum += noiseArr[counter++];
    }
    std::cout << "The sum for postive random junks from the memory is: " << sum << std::endl;
    sum = 0;
    counter = 100;
    do
    {
        std::cout << noiseArr[counter] << std::endl;
        sum += noiseArr[--counter];
    } while (counter > -1 && noiseArr[counter] >= 0);
    std::cout << "The sum for postive random junks from the memory in reverse is: " << sum << std::endl;
    
    

    // size of C++ data types
    std::cout << "\n\nSize of data types" << std::endl;

    std::cout << "char: " << sizeof(char) << " --> " << pow(2, (sizeof(char) * 8)) << " numbers." << std::endl;
    std::cout << "short: " << sizeof(short) << " --> " << pow(2, (sizeof(short) * 8)) << " numbers." << std::endl;
    std::cout << "int: " << sizeof(int) << " --> " << pow(2, (sizeof(int) * 8)) << " numbers." << std::endl;
    std::cout << "long: " << sizeof(long) << " --> " << pow(2, (sizeof(long) * 8)) << " numbers." << std::endl;
    std::cout << "long int: " << sizeof(long int) << " --> " << pow(2, (sizeof(long int) * 8)) << " numbers." << std::endl;
    std::cout << "long long: " << sizeof(long long) << " --> " << pow(2, (sizeof(long long) * 8)) << " numbers." << std::endl;
    std::cout << "float: " << sizeof(float) << " --> " << pow(2, (sizeof(float) * 8)) << " numbers." << std::endl;
    std::cout << "double: " << sizeof(double) << " --> " << pow(2, (sizeof(double) * 8)) << " numbers." << std::endl;

    // Functions
    //      Declaration
    //      Defination
    //      Prototyping
    //      Passing Arguments (By Value, By Reference)
    //      Function overloading
    std::cout << "\n\nFunctions (By Value and By Referrence)" << std::endl;
    int mouse = 10;
    int cat = 25;

    std::cout << "Before Doing Something" << std::endl;
    std::cout << "Mouse: " << mouse << std::endl;
    std::cout << "Cat: " << cat << std::endl;

    doSomethingWith(mouse, cat);
    doSomethingWith(mouse, cat);
    doSomethingWith(&mouse, &cat);

    std::cout << "After Doing Something twice" << std::endl;
    std::cout << "Mouse: " << mouse << std::endl;
    std::cout << "Cat: " << cat << std::endl;


    // Operator Overloading
    std::cout << "\n\nOperator Overloading" << std::endl;

    Vector vecA = {10, 20};
    Vector vecB = {10, 20};

    std::cout << "A = ";
    printVector(vecA);
    std::cout << std::endl;
    std::cout << "B = ";
    printVector(vecB);
    std::cout << std::endl;
    std::cout << toBool(vecA == vecB) << std::endl;

    std::cout << "A + B = ";
    printVector(vecA + vecB);
    std::cout << std::endl;

    // Overloading the << operator (Check the Inform definition)
    Inform newInfo = {MIERCOLES, "Weekly standup session", 3};
    std::cout << newInfo;    
    std::cout << toBool(newInfo == newInfo) << std::endl;

    // In-line function
    std::cout << min(1009, 7789) << std::endl;
    
    // Class
    std::cout << "\n\nClass" << std::endl;
    Counter ncounter;

    std::cout << "Initialization: " << ncounter.getCount() << std::endl;
    ncounter.increaseBy(4);
    std::cout << "Increased by Four: " << ncounter.getCount() << std::endl;
    ncounter.increaseBy(7);
    std::cout << "Then by Seven: " << ncounter.getCount() << std::endl;

    // Working with matrix with class

    Matrix matA;

    std::cout << matA << std::endl;

    int mm[] = {1, 3, 7, 0, 4, 2};

    Matrix matB(mm, 3, 2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << matB.getelement(i, j) << std::endl;
        }
    }

    std::cout << matB << std::endl;

    int arsize[] = {3, 4, 6};

    ndarray myArray(arsize, 4);

    // File System
    std::cout << "\n\nFile System" << std::endl;

    std::filesystem::path filep("/home/kmpk/Desktop/test.py");

    std::cout << "Root Name: " << filep.root_name() << std::endl;
    std::cout << "Root Directory: " << filep.root_directory() << std::endl;
    std::cout << "Root Path: " << filep.root_path() << std::endl;
    std::cout << "Relative Path: " << filep.relative_path() << std::endl;
    std::cout << "Parent Path: " << filep.parent_path() << std::endl;
    std::cout << "Filename: " << filep.filename() << std::endl;
    std::cout << "Stem: " << filep.stem() << std::endl;
    std::cout << "Extension: " << filep.extension() << std::endl;



    return EXIT_SUCCESS;
}

void doSomethingWith(int objectA, int& objectB)
{    
    std::cout << ++objectA << std::endl;
    std::cout << --objectB << std::endl;
}

void doSomethingWith(int* objectA, int* objectB)
{
    std::cout << ++*objectA << std::endl;
    std::cout << --*objectB << std::endl;
}

void compareScore(int n, int* a, int* b, int* result){
    //Calculates the scores of Alex and Bob

   int alex = 0;
   int bob = 0;

   for (int i = 0; i < n; i++){
       if (a[i] > b[i]) alex++;
       else if (a[i] < b[i]) bob++;
   }
   result[0] = alex;
   result[1] = bob;
}

void printArray(int* array, int size)
{
    printf("[%d, ", array[0]);
    for (int i = 1; i < size - 1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d]", array[size - 1]);
}

void printVector(const Vector& vector)
{
    std::cout << "Vector(" << vector.x << ", " << vector.y << ")";
}

std::string toBool(int x)
{
    if (x == 0) return "False";
    else return "True";
}

std::string dayTOString(SpanishDay day){
    std::string days[] = {
        "DOMINGO",
        "LUNES",
        "MARTEZ",
        "MIERCOLES",
        "JUEVES",
        "VIERNEZ",
        "SABADO"
    };

    return days[day];
}

SpanishVerb conjugate(SpanishVerb verb)
{
    std::string ending[] = { "o", "as", "a", "amos", "ais", "an"}; // AR Verbs
    SpanishVerb rootWord = verb;

    if (toLower(rootWord.substr(rootWord.size() - 1, rootWord.size())) == "ar" )
    {
        std::cout << (rootWord.substr(rootWord.size() - 1, rootWord.size())) << std::endl;
    }

    std::cout << (rootWord.substr(rootWord.size() - 2, rootWord.size())) << std::endl;

    return rootWord;
}

/** 
 * Return string UPPER case
 */
std::string toUpper(std::string text)
{
    std::string newText = "";
    for (int i = 0; i <  text.size(); i++)
    {
        char c = text[i];
        int value = (int)c;
        if (value > 96 && value < 123)
        {
            c = (char)(value - 32);
        }
        newText += c;
    }
    
    return newText;
    
}

/** 
 * Return string lower case
 */
std::string toLower(std::string text)
{
    std::string newText = "";
    for (int i = 0; i <  text.size(); i++)
    {
        char c = text[i];
        int value = (int)c;
        if (value > 64 && value < 91)
        {
            c = (char)(value + 32);
        }
        newText += c;
    }
    
    return newText;
    
}

/** 
 * Return string Title case
 */
std::string toTitle(std::string text)
{
    return toUpper(text.substr(0, 1)) + toLower(text.substr(1, text.size()));
}

/** 
 * Return string
 */
std::string toString(int value, std::string *map)
{    
    return map[value];
}