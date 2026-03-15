#ifndef INC_3M_MARATHON_DAY5_H
#define INC_3M_MARATHON_DAY5_H

#include <iostream>

class A {
public:
    A() {
        std::cout << "A object is created\n";
    }
    ~A() {
        std::cout << "A object is deleted\n";
    }
};

void week1_day5()
{
    std::cout << "Constructor/destructor\n";
    A a{};
    std::cout << "Some message goes here\n";
}

#endif //INC_3M_MARATHON_DAY5_H
