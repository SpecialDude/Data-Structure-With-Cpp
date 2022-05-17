// #include <math.h>
#include <iostream>

namespace GeneralStuff
{
    int product(const int* array, int size, int start = 0, int end = -1)
    {
        int p = 1;

        if (end < 0)
        {
            end = size;
        }

        for (int i = start; i < end; i++)
        {
            p *= array[i];
        }

        return p;
    }

    std::string repeat(std::string str, int times)
    {
        std::string repeatStr = "";
        for (int i = 0; i < times; i++)
        {
            repeatStr += str;
        }

        return repeatStr;
    }
    
    int randint(int start, int end)
    {
        int number = 4374605;

        return (number%end + start);
    }

    void printArray(const int* arr, int size, std::string sep = ", ", std::string end = "\n")
    {
        std::cout << "[";

        for (int i = 0; i < size - 1; i++)
        {
            std::cout << arr[i] << sep;
        }
        std::cout << arr[size - 1] << "]" << end;
    }
}

namespace NDarray
{
    class ndarray
    {
        public:
            ndarray();
            ndarray(int dimensionsBound[], int ds);
            ndarray(int* thearray, int dimensions[], int ds);
            ndarray(const ndarray& narray);
            ~ndarray();

            void operator==(const ndarray& narray);

            std::string tostring();
            int getravelelement(int i) const;
            int getelement(int indices[]) const;
            int getsize() const;
            int getdimension() const;
            int getcordinate(int i) const;
            const int* getshape() const;
            void reshape(int newshape[], int newdimension);
            std::string strshape();
            std::ostream& __str__(std::ostream& out, int dm, int start);

            // operations
            // Scalar operations

            //ndarray operator+(int scalar);
            void operator+(int scalar);

            
        private:
            int size;
            int dimension;
            int* narray;
            int* shape;
            int align;
    };
}

using namespace NDarray;

ndarray::ndarray()
{
    int d[] = {3, 3};
    ndarray(d, 2);
}

ndarray::ndarray(int dimensionsBound[], int ds)
{
    shape = new int[ds];
    dimension = ds;
    size = 1;
    
    for (int i = 0; i < ds; i++)
    {
        shape[i] = dimensionsBound[i];
        size *= dimensionsBound[i];
    }

    narray = new int[size];
}

ndarray::ndarray(int* thearray, int dimensions[], int ds):ndarray(dimensions, ds)
{
    for (int i = 0; i < size; i++)
    {
        narray[i] = thearray[i];
    }
}

ndarray::ndarray(const ndarray& array)
{
    dimension =  array.dimension;
    size = array.size;
}

ndarray::~ndarray()
{ 
    delete[] shape;
    delete[] narray;
}

int ndarray::getravelelement(int i) const {return narray[i];}
int ndarray::getsize() const {return size;}
int ndarray::getdimension() const {return dimension;}
int ndarray::getcordinate(int i) const {return shape[i];}
const int* ndarray::getshape() const {return shape;}
int ndarray::getelement(int indices[]) const
{
    int index = 0;
    for (int i = 0; i < dimension; i++)
    {       

        int ds = 1;

        for (int j = i + 1; j < dimension; j++)
        {
            ds *= shape[j];
        }

        index += indices[i] * ds;
    }

    return narray[index];
}

std::string ndarray::strshape()
{
    std::string strs = "ssss";

    for (int i = 0; i < dimension; i++)
    {
        strs += (shape[i] + "x");
    }

    return strs;
}

std::string ndarray::tostring()
{
    std::string strRepr = "[" + narray[0];
    strRepr += ", ";

    for (int i = 1; i < size - 1; i++)
    {
        strRepr += narray[i] + ", ";
    }

    strRepr += narray[size-1] + "]";

    return strRepr;

}

std::ostream& operator<<(std::ostream& out, ndarray& array)
{
    return array.__str__(out, array.getdimension(), 0);
}

void ndarray::reshape(int newshape[], int newdimension)
{
    if (GeneralStuff::product(newshape, newdimension) == size)
    {
        for (int i = 0; i < newdimension; i++)
        {
            shape[i] = newshape[i];
        }
        dimension = newdimension;
    } else {std::cout << "Not a perfect shape" << std::endl;}
}

std::ostream& ndarray::__str__(std::ostream& out, int dm, int start)
{
    
    if (dm == 1)
    {
        out << "[";

        int stop = start + shape[dimension - 1];
        for (int i = start; i < stop - 1; i++)
        {
            out << narray[i] << "    ";
        }

        out << narray[stop - 1] << "]";

        return out;
    }
    else
    {
        if (dimension > 2) out << "[";

        int size = shape[dimension - dm];

        for (int i = 0; i < size - 1; i++)
        {
            int s = GeneralStuff::product(shape, dimension, (dimension - dm + 1)) * i + start;            
            this->__str__(out, dm - 1, s);
            out << GeneralStuff::repeat("\n", dm - 1);
        }
        int s = GeneralStuff::product(shape, dimension, (dimension - dm + 1)) * (size - 1) + start;            
        this->__str__(out, dm - 1, s);

        if (dimension > 2) out << "]";
    }

    return out;
}

// Operations
/* ndarray ndarray::operator+(int scalar)
{
    ndarray newArray(shape, dimension);

    for (int i = 0; i < size; i++)
    {
        newArray.narray[i] = narray[i] * scalar;
    }
    return newArray;
} */

void ndarray::operator+(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        narray[i] = narray[i] + 2;
    }
}

int main()
{
    int shape[] = {3, 4};
    int array[] = {43, 30, -2, 40, -3, 49, 75, 17, 13, 39, -4, 10};
    ndarray myArray(array, shape, 2);
    
    /* int ds[] = {2, 2, 2, 2};
    int arr[] = {36, 3, 89, -10, 24, 0, 2, -9, 90, 20, -3, 1, -9, 7, -2, 15};
    ndarray oneDarray(arr, ds, 4);

    std::cout << "NArray 1 (2, 2, 2, 2)" << std::endl;
    std::cout << "Dimension: " << oneDarray.getdimension() << std::endl;
    std::cout << "Shape: ";
    GeneralStuff::printArray(oneDarray.getshape(), oneDarray.getdimension());
    std::cout << oneDarray << std::endl;


    std::cout << "\n\n" << std::endl;

    int nds[] = {2, 2, 4};
    oneDarray.reshape(nds, 3);

    std::cout << "NArray 2 (2, 2, 4)" << std::endl;
    std::cout << "Dimension: " << oneDarray.getdimension() << std::endl;
    std::cout << "Shape: ";
    GeneralStuff::printArray(oneDarray.getshape(), oneDarray.getdimension());
    std::cout << oneDarray << std::endl;

    std::cout << "\n\n" << std::endl;

    int tds[] = {4, 4};
    oneDarray.reshape(tds, 2);
 
    std::cout << "NArray 3 (4, 4)" << std::endl;
    std::cout << "Dimension: " << oneDarray.getdimension() << std::endl;
    std::cout << "Shape: ";
    GeneralStuff::printArray(oneDarray.getshape(), oneDarray.getdimension());
    std::cout << oneDarray << std::endl;

    std::cout << "\n\n" << std::endl;

    int kds[] = {16, 1, 1};
    oneDarray.reshape(kds, 3);

    std::cout << "NArray 3 (16, 1, 1)" << std::endl;
    std::cout << "Dimension: " << oneDarray.getdimension() << std::endl;
    std::cout << "Shape: ";
    GeneralStuff::printArray(oneDarray.getshape(), oneDarray.getdimension());
    std::cout << oneDarray << std::endl; */

   
    // int d[] = {2, 2, 5};
    // int m[] = {3, 2, 9, 0, 1, 3, 5, 4, -1, 10, 14, 32, -12, 29, -2, -3, 20, -60, 45, 19};

    /* int m[] = {3, 2, 9, 0, 1, 3, 5, 4, -1, 10, 14, 32};
    int d[] = {2, 6};

    ndarray myArray(m, d, 2);

    std::cout << myArray << std::endl;
    std::cout << "\n\n" << std::endl;

    d[0] = 6;
    d[1] = 2;
    myArray.reshape(d, 2);

    std::cout << myArray << std::endl;

    int indices[] = {5, 1, 1};
    std::cout << myArray.getelement(indices) << std::endl; */   


    return EXIT_SUCCESS;
}