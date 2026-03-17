#ifndef INC_3M_MARATHON_DAY3_H
#define INC_3M_MARATHON_DAY3_H

#include <iostream>

/* Heap, size - run time
 * */
void vec1()
{
    int s = 10;

    double* elem{ new double[s] }; // double* elem; elem = new double[s];
    elem[0] = 1.2;
    std::cout << "Heap array.\nAddress: " << elem << "\n";
    std::cout << "Value of  1st el=" << elem[0] << "\n";
    std::cout << "Value of 10th el=" << elem[9] << "\n";
    for (double* p = elem; p != elem + s; ++p)
        std::cout << *p << ", ";
    std::cout << std::endl;
    delete[] elem;
}

/* Stack, size - compiled time
 * */
void vec2()
{
    const int s = 10;
    double arr[s] = {1.0, 2.0, 3.0};
    arr[8] = 1.2;
    std::cout << "Stack array.\nAddress: " << arr << "\n";
    std::cout << "Value of 2nd el=" << arr[2] << "\n";
    std::cout << "Value of 9th el=" << arr[8] << "\n";
    std::cout << "Value of 10th el=" << arr[9] << "\n";
    for (auto el: arr)
        std::cout << el << ", ";
    std::cout << std::endl;
}

void week1_day3()
{
    std::cout << "Hello world\n";
    vec1();
    vec2();
}

#endif //INC_3M_MARATHON_DAY3_H
