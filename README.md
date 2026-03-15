# 3m-marathon
C++ Marathon (3 months)

Idea is to run through C++17 and refresh/close gaps.


## Month 1 - basics

### Week 1 - memory and lifetime
* stack vs heap
* object lifetime
* RAII
* constructors / destructors
* rule of 0 / 3 / 5

#### stack vs heap
- in stack - compiler/scope controls a lifetime of an object 
- in heap - developer or RAII object
```c++
void f() {
    int a = 5;        // stack
    int* b = new int; // heap
}
// after leaving the fn a is freed, b is memory leak
```

#### object lifetime
- object lives between constructor and destructor
```c++
{
    A obj;
    // obj lives
} // no more obj 
```

#### RAII - Resource Acquisition Is Initialization

example of resources:
- heap memory
- file
- mutex
- socket
- database connection

Resource is captured in constructor and released in destructor
```c++
{
    std::lock_guard<std::mutex> lock(m);
} mutex here is automatically unlocked
```

Nice example of correct RAII usage
```c++
class File {
public:
    File(const char* path) {
        f = fopen(path,"r");
    }

    ~File() {
        fclose(f);
    }

private:
    FILE* f;
};
```

#### constructors / destructors

We create and we destroy
```c++
class A {
    A() = default;
    ~A() = default; // free object resources
};
```
Another example:
```c++
std::vector<A> v(10); // 10 constructor calls

// when remove v, there'll be 10 destructor calls
// destructors are called in reverse order 10, 8, .. 2, 1
```

Practice:
```shell
# create classes
- FileReader
- Logger
- Timer
```

Note: CppCon 'Back to Basics: RAII' by Arthur O'Dwyer

### Week 2 - move semantics
* lvalue
* rvalue
* move ctor
* move assignment
* std::move

Practice:
```shell
# create class
- Buffer
```

### Week 3 - references and API
* reference
* const reference
* string_view
* span
* optional
* variant

Practice:
```shell
# re-write
const std::string&
→
std::string_view
```

### Week 4 - classes and polymorphism
* virtual
* override
* vtable
* object slicing
* composition

Practice:
```shell
# create
Shape
Circle
Rectangle

# compare
* inheritance
* composition.
```

## Month 2 - modern C++

### Week 5 - stl containers
* vector
* deque
* unordered_map
* map
* set
* array

#### extra
* iterator invalidation
* complexity

Practice:
```shell
# write LRU cache
```

### Week 6 - algorithms
* std::transform
* std::find_if
* std::sort
* std::accumulate

#### extra
* find
* sort
* count
* all_of
* any_of
* copy
* remove_if

Practice:
```
# re-write several loops using STL
```

### Week 7 - error handling
* exceptions
* optional
* error codes
* expected pattern

### Week 8 - architecture
* SOLID
* composition vs inheritance
* dependency inversion
* layered architecture

Practice:
```shell
# design of a server
Machine
Job
Scheduler
API
```


## Month 3 - system development

### Week 9 - concurrency
* thread
* mutex
* lock_guard
* condition_variable
* atomic

Practice:
```shell
# write
thread safe queue
```

Note: CppCon 'C++ Concurrency From the Ground Up' by Fedor Pikus


### Week 10 - build system
* CMake targets
* libraries
* include directories
* linking
* build types
* static vs shared
* dependency management

Note: Book ['Professional CMake: A Practical Guide'](https://crascit.com/professional-cmake/) by Craig Scott 


### Week 11 - testing
* gtest
* unit tests
* integration tests
* mocking

### Week 12 - prep
* RAII
* move semantics
* smart pointers
* vector vs list
* iterator invalidation

Practice:
```shell
LRU cache
thread safe queue
rate limiter
```

### Bonus C++20
* concepts
* ranges
* span
* format
* jthread


## Source of truth

### books
* A Tour of C++ (Stroustrup)
* Effective Modern C++ (Scott Meyers)

### documentation and conferences
* cppreference :D
* CppCon (speakers: Herb Sutter, Chandler Carruth)

### extra books
* Designing Data‑Intensive Applications (Martin Kleppmann)
* C++ Concurrency in Action (Anthony Williams) 
* Professional CMake: A Practical Guide (Craig Scott)


## Machine Job Scheduler (mini project)
a small job scheduling system in C++ with worker threads and REST API


