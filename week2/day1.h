#ifndef INC_3M_MARATHON_DAY11_H
#define INC_3M_MARATHON_DAY11_H


#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include <utility>


class Buffer {
public:
    Buffer() = default;

    explicit Buffer(std::size_t n)
        : size_(n), data_(n ? new int[n] : nullptr) {
    }

    ~Buffer() {
        delete[] data_;
    }

    // copy ctor (deep copy)
    Buffer(const Buffer& other)
        : size_(other.size_),
        data_(other.size_ ? new int[other.size_] : nullptr)
    {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // copy assignment (via copy-and-swap for reliability)
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        Buffer tmp(other);
        swap(tmp);
        return *this;
    }

    // move ctor: "grab" resource from other
    Buffer(Buffer&& other) noexcept
        : size_(other.size_), data_(other.data_)
    {
        other.size_ = 0;
        other.data_ = nullptr;

        // or data_ = std::move(other.data_);
    }

    // move assignment: free own resource and take the other's
    Buffer& operator=(Buffer&& other) noexcept {
        if (this == &other) return *this; // protection from self-move

        delete[] data_; // free current resource

        size_ = other.size_;
        data_ = other.data_;

        other.size_ = 0;
        other.data_ = nullptr;

        return *this;
    }

    void swap(Buffer& other) noexcept {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    std::size_t size() const { return size_; }
    int* data() const { return data_; }

private:
    std::size_t size_ = 0;
    int* data_ = nullptr;
};


std::string getName() {
    return "Guest";
}

struct w2_A {
    std::vector<int> v;

    w2_A() = default;

    // move ctor - create a new object by stealing resources 
    //             from the source object
    w2_A(w2_A&& other) noexcept : v(std::move(other.v)) {}
};

struct w2_B {
    std::vector<int> v;

    // move assignment - assign new values to an existing object 
    //                   by stealing resources from the source object
    w2_B& operator=(w2_B&& other) noexcept {
        v = std::move(other.v);
        return *this;
    }
};

void w2_lvalue_rvalue()
{
    std::cout << "L-value and R-value\n";

    int x = 10;  // 'x' - is a lvalue, it has address and name
    //  10 - is a rvalue, no address, just a number

    int* ptr = &x;
    ptr[0] = 20;  // This is valid, as ptr[0] is equivalent to *ptr
    std::cout << "Val of x is " << x << ", ptr[0] = 20 " << std::endl; // This will print 20
    *ptr = 30;    // This is also valid
    std::cout << "Val of x is " << x << ", *ptr = 30 " << std::endl; // This will print 30
    x -= 15;
    std::cout << "Val of x is " << x << ", x -= 15 " << std::endl; // This will print 15


    int y = x + 5; // '(x + 5)' — is rvalue. Calculation result is temp

    std::string guestName = getName(); // 'getName()' returns a temporary object
    // is rvalue.

//int* ptr = &(x + 5); // can't take an address of temp value
                       // E0158: expression must be an lvalue or a function designator
}

void w2_move_semantics()
{
    {
        w2_A x;
        x.v = { 1, 2, 3 };
        int x_size = x.v.size();

        w2_A y = std::move(x); // calls move constructor (if it is available), otherwise copy constructor
        std::cout << "\nMove semantics\n";
        std::cout << "Before x.v size: " << x_size << ", y.v size: 0" << std::endl;
        std::cout << "After  x.v size: " << x.v.size() << ", y.v size: " << y.v.size() << std::endl;

        w2_B a, b;
        a.v = { 4, 5, 6 };
        b.v = { 1, 2 };
        int a_size = a.v.size();
        int b_size = b.v.size();
        b = std::move(a);
        std::cout << "\nBefore a.v size: " << a_size << ", b.v size: " << b_size << std::endl;
        std::cout << "After  a.v size: " << a.v.size() << ", b.v size: " << b.v.size() << std::endl;
    }

    {
        std::cout << "\nMove semantics: Buffer example\n";
        Buffer a(5);
        std::cout << "a: size=" << a.size() << ", ptr=" << (void*)a.data() << "\n";

        // move ctor (new object initialization)
        Buffer b = std::move(a);
        std::cout << " - after move-ctor:\n";
        std::cout << "a: size=" << a.size() << ", ptr=" << (void*)a.data() << "\n";
        std::cout << "b: size=" << b.size() << ", ptr=" << (void*)b.data() << "\n";

        Buffer c(3);
        std::cout << "c: size=" << c.size() << ", ptr=" << (void*)c.data() << "\n";

        // move assignment (assignment to existing object)
        c = std::move(b);
        std::cout << " - after move-assign:\n";
        std::cout << "b: size=" << b.size() << ", ptr=" << (void*)b.data() << "\n";
        std::cout << "c: size=" << c.size() << ", ptr=" << (void*)c.data() << "\n";
    }
}

void w2_d1_examples()
{
    {
        std::cout << "\n ------------ 0 / 3 / 5 ------------ \n";
        std::cout << "A() = default; \t\t\t\t - ctor\n"
            "~A() = default; \t\t\t - dtor\n"
            "A(const A&) = default; \t\t\t - copy ctor\n"
            "A& operator=(const A&) = default; \t - copy assignment\n"
            "A(A&&) = default; \t\t\t - move ctor\n"
            "A& operator=(A&&) = default; \t\t - move assignment";
        std::cout << "\n ----------------------------------- \n";
    }

    {
        std::cout << "\nExamples\n";
        std::vector<int> data;
        std::vector<int> data2;
        data.resize(1'000'000, 55); // all 55, data.resize(1'000'000) - will give us 0 values

        std::cout << "data1 size is = " << data.size() << ", 5th elem = " << data[4] << "\n";
        std::cout << "data2 size is = " << data2.size() << "\n";

        data2 = std::move(data);
        std::cout << "After move assignment - std::move()\n";

        std::cout << "data1 size is = " << data.size() << "\n";
        std::cout << "data2 size is = " << data2.size() << ", 5th elem = " << data2[4] << "\n";
    }
}

struct w1_a1 {
    std::vector<int> data;
};

void week2_day1()
{
    w2_lvalue_rvalue();
    w2_move_semantics();
    // w2_d1_examples();
    {
        std::cout << "\n\nTo understand\n\n";
        std::cout << "BadVector a1(10);\n"
            "BadVector a2 = a1;\t\t // initialization -> call COPY CTOR\n"
            "BadVector a3 = std::move(a1);\t // initialization -> call MOVE CTOR (if exists)\n";
        std::cout << "\n\n";
        std::cout << "BadVector a1(10);\n"
            "BadVector a2(5);\t // a2 already exists\n"
            "a2 = a1;\t\t // Assignment -> call OPERATOR assignment copy\n"
            "a2 = std::move(a1);\t // Assignment -> call OPERATOR assignment move\n";
    }
    
}

#endif //INC_3M_MARATHON_DAY11_H