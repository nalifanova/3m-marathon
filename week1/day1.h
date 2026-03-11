#ifndef INC_3M_MARATHON_DAY1_H
#define INC_3M_MARATHON_DAY1_H

#include <iostream>
#include <exception>

int catch_error()
{
    try
    {
        throw std::runtime_error("There is an error");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

int print_args(int a, int b, const std::string& greetings, std::string& name, int c)
{
    std::cout << "We are printing all args: "
              << a << ", " << b << ", " << greetings << ", " << name << ", "
              << c << "\n";
}

int skip_args(int, int, const std::string&, std::string& name, int)
{
    std::cout << "We are skipping first three args, " << name
              << ", and the last one too\n";
}

void week1_day1()
{
    std::string hello = "Hello";
    std::string name = "Peter";
    print_args(1, 2, hello, name, 3);
    skip_args(1, 2, hello, name, 3);

    catch_error();
}

#endif //INC_3M_MARATHON_DAY1_H
