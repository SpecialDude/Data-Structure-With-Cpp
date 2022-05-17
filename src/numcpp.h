// #pragma once
#include <iostream>
#ifndef _Numcpp
#define _Numcpp

namespace Numcpp
{
    class ndarray
    {
        private:
            int m_size;
            int m_dimension;
            int m_align = 4;
            int* m_shape;
            int* m_narray;

        public:
            ndarray();
            ndarray(int dimension, const int* shape);
            ndarray(int dimension, const int* shape, int* array);
            ndarray(const ndarray& ndarray_instance);
            ndarray& operator=(const ndarray& ndarray_instance);
            ~ndarray();
            std::ostream& __str__(std::ostream& out, int dimension, int start) const;

            //Getters
            int dimension() const;
            int element_at(int* indices) const;
            int length(int index = 0) const;
            int size() const;
            int ravel_element_at(int index) const;
            const int* const shape() const;

            // Setters
            void reshape(int new_dimension, int* newShape);

            // Operations
    };

    std::ostream& operator<<(std::ostream& out, const ndarray& ndarray_instance);

    void operator++(ndarray& ndarray_instance);
    void operator--(ndarray& ndarray_instance);
    ndarray operator==(const ndarray& ndarray_instance_A, const ndarray& ndarray_instance_B);    
    ndarray operator>(const ndarray& ndarray_instance_A, const ndarray& ndarray_instance_B);
    ndarray operator<(const ndarray& ndarray_instance_A, const ndarray& ndarray_instance_B);
    ndarray operator>=(const ndarray& ndarray_instance_A, const ndarray& ndarray_instance_B);
    ndarray operator<=(const ndarray& ndarray_instance_A, const ndarray& ndarray_instance_B);
    ndarray operator==(const ndarray& ndarray_instance_A, int scalar);
    ndarray operator>(const ndarray& ndarray_instance_A, int scalar);
    ndarray operator<(const ndarray& ndarray_instance_A, int scalar);
    ndarray operator>=(const ndarray& ndarray_instance_A, int scalar);
    ndarray operator<=(const ndarray& ndarray_instance_A, int scalar);

    ndarray operator+(const ndarray& ndarray_instance, int scalar);
    ndarray operator+(int scalar, const ndarray& ndarray_instance);
    ndarray operator*(const ndarray& ndarray_instance, int scalar);
    ndarray operator*(int scalar, const ndarray& ndarray_instance);
    ndarray operator-(const ndarray& ndarray_instance, int scalar);
    ndarray operator-(int scalar, const ndarray& ndarray_instance);
    ndarray operator/(const ndarray& ndarray_instance, int scalar);
    ndarray operator/(int scalar, const ndarray& ndarray_instance);
    ndarray operator%(const ndarray& ndarray_instance, int scalar);
    ndarray operator%(int scalar, const ndarray& ndarray_instance);

    namespace GeneralStuff
    {
        void printArray(const int* arr, int size, int start = 0, int end = -1, const char* sep = ", ", const char* endl = "\n");
        int product(const int*, int size, int start = 0, int end = -1);
        void copyArray(int* m_arr, const int* const arr, int size, int start = 0, int end = -1);
        bool compareArray(const int* const arr_1, const int* const arr_2, int size);
        std::string repeat(std::string str, int times);
        std::string rjust(std::string str, int width, std::string fill = " ");
        std::string ljust(std::string str, int width, std::string fill = " ");
        std::string center(std::string str, int width, std::string fill = " ");
    }
}
#endif