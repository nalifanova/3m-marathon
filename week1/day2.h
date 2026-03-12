#ifndef INC_3M_MARATHON_DAY2_H
#define INC_3M_MARATHON_DAY2_H

#include <iostream>
#include <string>

constexpr int kTimeInDays = 60 * 24;

constexpr int showTime(int days)
{
    return kTimeInDays * days;
}

constexpr int kFiveDays = showTime(5);

/* count the number of occurrences of x in p[]
 p is assumed to point to a zero-terminated array of char (or to nothing)
 */
int count_x(char* p, char x)
{
    int count = 0;
    // there was an error in example `while (p)` - is always true!
    // while (p) { - we should check a symbol, not a pointer
    while (*p) {
        if (*p==x)
            ++count;
        ++p;
    }
    return count;
}

int count_y(const char* p, const char* end, char x)
{
    int count = 0;
    while (p != end) {
        if (*p == x)
            ++count;
        ++p;
    }
    return count;
}

void week1_day2()
{
    const int nElements = 10;
    std::cout << "Run time calc & compile time calc\n";
    std::cout << "day  5, seconds " << kFiveDays << "\n";
    int days = 1;
    std::cout << "days " << days << ",  seconds " << showTime(days) << "\n";
    days = 3;
    std::cout << "days " << days << ",  seconds " << showTime(days) << "\n";

    std::cout << "\nCount the number of occurrences (C-style)\n";
    // equal arrays C-style null-terminated
    char v_[nElements] {'a', 'b', 'c', 'a', 'd', 'f', 'a', 'b', 'c', '\0'};
    char v[] = "abcadfabc";
    std::cout << "a = " << count_x(v, 'a') << "\n";
    std::cout << "c = " << count_x(v, 'c') << "\n";

    std::cout << "Count the number of occurrences (C++ style)\n";
    // is NOT null-terminated
    const char w[nElements] {'a','b','c','a','d','b','b','b','k','c'};
    std::cout << "a = " << count_y(w, w + nElements, 'a') << "\n";
    std::cout << "b = " << count_y(w, w + nElements, 'b') << "\n";
}

#endif //INC_3M_MARATHON_DAY2_H
