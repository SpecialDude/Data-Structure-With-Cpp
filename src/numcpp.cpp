#include <iostream>
#include "numcpp.h"


 
using namespace Numcpp;

ndarray::ndarray()
{
    std::cout << "Default Constructor" << std::endl;
}

ndarray::ndarray(int dimension, const int* shape) : m_dimension(dimension)
{
    m_shape = new int[m_dimension];

    GeneralStuff::copyArray(m_shape, shape, m_dimension);
    m_size = GeneralStuff::product(m_shape, m_dimension);

    m_narray = new int[m_size];
}

ndarray::ndarray(int dimension, const int* shape, int* array) : ndarray(dimension, shape)
{
    GeneralStuff::copyArray(m_narray, array, m_size);
}

ndarray::ndarray(const ndarray& ndarray_instance)
{
    m_size = ndarray_instance.m_size;
    m_dimension = ndarray_instance.m_dimension;
    m_align = ndarray_instance.m_align;

    m_shape = new int[m_dimension];
    GeneralStuff::copyArray(m_shape, ndarray_instance.m_shape, m_dimension);

    m_narray = new int[m_size];
    GeneralStuff::copyArray(m_narray, ndarray_instance.m_narray, m_size);
}

ndarray& ndarray::operator=(const ndarray& ndarray_instance)
{
    // std::cout << ((int*)((char*)m_narray + 20))[0] << std::endl;
    if (this != &ndarray_instance)
    {
        delete[] m_shape;
        delete[] m_narray;
        m_size = ndarray_instance.m_size;
        m_dimension = ndarray_instance.m_dimension;
        m_align = ndarray_instance.m_align;

        m_shape = new int[m_dimension];
        GeneralStuff::copyArray(m_shape, ndarray_instance.m_shape, m_dimension);

        m_narray = new int[m_size];
        GeneralStuff::copyArray(m_narray, ndarray_instance.m_narray, m_size);
    }
    return *this;
    
}

ndarray::~ndarray()
{
    delete[] m_shape;
    delete[] m_narray;
    std::cout << "Destructor:: Object destroyed" << std::endl;
}

int ndarray::dimension() const {return m_dimension;}

int ndarray::size() const {return m_size;}

int ndarray::ravel_element_at(int index) const {return m_narray[index];}

const int* const ndarray::shape() const {return m_shape;}

std::ostream& ndarray::__str__(std::ostream& out, int dimension, int start) const
{
    if (dimension == 1)
    {
        out << "[";
        int stop = start + m_shape[m_dimension - 1];

        for (int i = start; i < stop - 1; i++)
        {
            out << m_narray[i] << "   ";
        }
        out << m_narray[stop - 1] << "]";
    }

    else
    {
        if (m_dimension > 2) out << "[";

        int size = m_shape[m_dimension - dimension];

        for (int i = 0; i < size -1; i++)
        {
            int s = GeneralStuff::product(m_shape, m_dimension, (m_dimension - dimension + 1)) * i + start;
            this->__str__(out, dimension - 1, s);
            out << GeneralStuff::repeat("\n", dimension - 1);
        }
        int s = GeneralStuff::product(m_shape, m_dimension, (m_dimension - dimension + 1)) * (size - 1) + start;
        this->__str__(out, dimension - 1, s);

        if (m_dimension > 2) out << "]";
    }

    return out;
}

std::ostream& Numcpp::operator<<(std::ostream& out, const ndarray& ndarray_instance)
{
    return ndarray_instance.__str__(out, ndarray_instance.dimension(), 0);
}

ndarray Numcpp::operator+(const ndarray& ndarray_instance, int scalar)
{
    int arr[ndarray_instance.size()];

    for (int i = 0; i < ndarray_instance.size(); i++)
    {
        arr[i] = ndarray_instance.ravel_element_at(i) + scalar;
    }

    return ndarray(ndarray_instance.dimension(), ndarray_instance.shape(), arr);
}

ndarray Numcpp::operator+(int scalar, const ndarray& ndarray_instance)
{
    return ndarray_instance + scalar;
}

ndarray Numcpp::operator*(const ndarray& ndarray_instance, int scalar)
{
    int arr[ndarray_instance.size()];

    for (int i = 0; i < ndarray_instance.size(); i++)
    {
        arr[i] = ndarray_instance.ravel_element_at(i) * scalar;
    }

    return ndarray(ndarray_instance.dimension(), ndarray_instance.shape(), arr);
}

ndarray Numcpp::operator*(int scalar, const ndarray& ndarray_instance)
{
    return ndarray_instance * scalar;
}

ndarray Numcpp::operator-(const ndarray& ndarray_instance, int scalar)
{
    int arr[ndarray_instance.size()];

    for (int i = 0; i < ndarray_instance.size(); i++)
    {
        arr[i] = ndarray_instance.ravel_element_at(i) - scalar;
    }

    return ndarray(ndarray_instance.dimension(), ndarray_instance.shape(), arr);
}

ndarray Numcpp::operator-(int scalar, const ndarray& ndarray_instance)
{
    return ndarray_instance - scalar;
}

ndarray Numcpp::operator/(const ndarray& ndarray_instance, int scalar)
{
    int arr[ndarray_instance.size()];

    for (int i = 0; i < ndarray_instance.size(); i++)
    {
        arr[i] = ndarray_instance.ravel_element_at(i) / scalar;
    }

    return ndarray(ndarray_instance.dimension(), ndarray_instance.shape(), arr);
}

ndarray Numcpp::operator/(int scalar, const ndarray& ndarray_instance)
{
    return ndarray_instance / scalar;
}

ndarray Numcpp::operator%(const ndarray& ndarray_instance, int scalar)
{
    int arr[ndarray_instance.size()];

    for (int i = 0; i < ndarray_instance.size(); i++)
    {
        arr[i] = ndarray_instance.ravel_element_at(i) % scalar;
    }

    return ndarray(ndarray_instance.dimension(), ndarray_instance.shape(), arr);
}

ndarray Numcpp::operator%(int scalar, const ndarray& ndarray_instance)
{
    return ndarray_instance % scalar;
}

void ndarray::reshape(int new_dimension, int* new_shape)
{
    if (GeneralStuff::product(new_shape, new_dimension) == m_size)
    {
        

        if (m_dimension != new_dimension)
        {
            m_dimension = new_dimension;
            delete[] m_shape;
            m_shape = new int[m_dimension];
        }
        

        GeneralStuff::copyArray(m_shape, new_shape, m_dimension);
    }
}

int ndarray::element_at(int* indices) const
{
    int index = 0;
    
    for (int i = 0; i < m_dimension; i++)
    {
        int ds = GeneralStuff::product(m_shape, m_dimension, i + 1);
        index += indices[i] * ds;
    }

    return m_narray[index];    
}

int ndarray::length(int index) const
{
    return m_shape[index];
}


void GeneralStuff::printArray(const int* arr, int size, int start, int end, const char*  sep, const char* endl)
{
    if (end < 0) end = size;

    std::cout << "[";

    for (int i = start; i < end - 1; i++)
    {
        std::cout << arr[i] << sep;
    }

    std::cout << arr[end - 1] << "]" << endl;;
}

int GeneralStuff::product(const int* arr, int size, int start, int end)
{
    if (end < 0) end = size;
    int p = 1;

    for (int i = start; i < end; i++)
    {
        p *= arr[i];
    }

    return p;
}

void GeneralStuff::copyArray(int* m_arr, const int* const arr, int size, int start, int end)
{
    if (end < 0) end = size;

    for (int i = 0; i < size; i++)
    {
        m_arr[i] = arr[i];
    }
}

std::string GeneralStuff::repeat(std::string str, int times)
{
    std::string repeatStr = "";
    for (int i = 0; i < times; i++)
    {
        repeatStr += str;
    }

    return repeatStr;
}

std::string GeneralStuff::ljust(std::string str, int width, std::string fill)
{
    int rem = width - str.length();
    // if (rem < 0) rem = 0;
    return (str + GeneralStuff::repeat(fill, rem));
}

std::string GeneralStuff::rjust(std::string str, int width, std::string fill)
{
    int rem = width - str.length();
    return (GeneralStuff::repeat(fill, rem) + str);
}

std::string GeneralStuff::center(std::string str, int width, std::string fill)
{
    int rem = width - str.length();
    int mid = rem / 2;
    int rest = rem - mid;
    return (GeneralStuff::repeat(fill, rest) + str + GeneralStuff::repeat(fill, mid));
}

bool GeneralStuff::compareArray(const int* const arr_1, const int* const arr_2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr_1[i] != arr_2[i]) return false;
    }
    return true;
}