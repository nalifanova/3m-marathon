#ifndef INC_3M_MARATHON_DAY4_H
#define INC_3M_MARATHON_DAY4_H

#include <iostream>

enum class Color { red = 2, blue = 9 , green = 12};
enum class TrafficLight { green, yellow, red};

void week1_day4()
{
    std::cout << "Good practice to use enum class over enum\n";
    Color red1 = Color::red;
    TrafficLight red2 = TrafficLight::red;

    // red1 != red2 - two different types
    // int i = Color::red; // error : Color::red is not an int
    // Color c = 2;        // error : 2 is not a Color

    std::cout << static_cast<int>(red1) << "\n";
    std::cout << static_cast<int>(red2) << "\n";
}


#endif //INC_3M_MARATHON_DAY4_H
