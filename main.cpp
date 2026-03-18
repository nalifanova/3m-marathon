#include "week1/week.h"
#include "week2/week.h"

#include <iostream>


static void week1()
{
    std::cout << "Week 1: Day1\n";
    week1_day1();
    std::cout << "\nWeek 1: Day2\n";
    week1_day2();
    std::cout << "\nWeek 1: Day3\n";
    week1_day3();
    std::cout << "\nWeek 1: Day4\n";
    week1_day4();
    std::cout << "\nWeek 1: Day5\n";
    week1_day5();
    std::cout << "\nWeek 1: Day6\n";
    week1_day6();
}

static void week2()
{
    std::cout << "Week 2: Day1\n";
    week2_day1();
}

int main()
{
    week2();

    return 0;
}
