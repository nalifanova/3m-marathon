#ifndef INC_3M_MARATHON_DAY6_H
#define INC_3M_MARATHON_DAY6_H

#include <vector>


class RuleA {
    RuleA() = default;
    ~RuleA() = default;
};


class BadVector
{
public:
    explicit BadVector(int s)
    {
        m_elem = new double[s];
        m_sz = s;
    }

    ~BadVector()
    {
        delete[] m_elem;
    }

private:
    double* m_elem;
    int m_sz;
};


class ThreeRuleVector
{
public:

    ThreeRuleVector(int s)
    {
        m_elem = new double[s];
        m_sz = s;
    }

    ~ThreeRuleVector()
    {
        delete[] m_elem;
    }

    // copy constructor
    ThreeRuleVector(const ThreeRuleVector& other)
    {
        m_sz = other.m_sz;
        m_elem = new double[m_sz];
        std::copy(other.m_elem, other.m_elem + m_sz, m_elem);
    }

    // copy assignment
    ThreeRuleVector& operator=(const ThreeRuleVector& other)
    {
        if (this == &other)
            return *this;

        delete[] m_elem;

        m_sz = other.m_sz;
        m_elem = new double[m_sz];
        std::copy(other.m_elem, other.m_elem + m_sz, m_elem);

        return *this;
    }

private:
    double* m_elem;
    int m_sz;
};


class FiveRuleVector
{
public:

    FiveRuleVector(int s)
    {
        m_elem = new double[s];
        m_sz = s;
    }

    // destructor
    ~FiveRuleVector()
    {
        delete[] m_elem;
    }

    // copy constructor
    FiveRuleVector(const FiveRuleVector& other)
    {
        m_sz = other.m_sz;
        m_elem = new double[m_sz];
        std::copy(other.m_elem, other.m_elem + m_sz, m_elem);
    }

    // move constructor
    FiveRuleVector(FiveRuleVector&& other) noexcept
    {
        m_sz = other.m_sz;
        m_elem = other.m_elem;

        other.m_elem = nullptr;
        other.m_sz = 0;
    }

    // copy assignment
    FiveRuleVector& operator=(const FiveRuleVector& other)
    {
        if (this == &other) // if omit this check, we can delete our own data and catch UB
            return *this;

        delete[] m_elem;

        m_sz = other.m_sz;
        m_elem = new double[m_sz];
        std::copy(other.m_elem, other.m_elem + m_sz, m_elem);

        return *this;
    }

    // move assignment
    FiveRuleVector& operator=(FiveRuleVector&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] m_elem;

        m_sz = other.m_sz;
        m_elem = other.m_elem;

        other.m_elem = nullptr;
        other.m_sz = 0;

        return *this;
    }

private:
    double* m_elem;
    int m_sz;
};


class ZeroVector
{
public:
    ZeroVector(int s)
        : m_data(s) {
    }
private:
    std::vector<double> m_data;
};


class BetterVector
{
public:
    // Default constructor
    BetterVector()
        : m_sz(0), m_elem(nullptr) {
    }

    // Constructor with size
    explicit BetterVector(int s)
        : m_sz(s), m_elem(std::make_unique<double[]>(s)) {
    }

    // Destructor (no need, 'coz std::unique_ptr automatically frees up memory)

    // Copy constructor
    BetterVector(const BetterVector& other)
        : m_sz(other.m_sz), m_elem(std::make_unique<double[]>(other.m_sz))
    {
        std::copy(other.m_elem.get(), other.m_elem.get() + m_sz, m_elem.get());
    }

    // Move constructor
    BetterVector(BetterVector&& other) noexcept
        : m_sz(std::exchange(other.m_sz, 0)), m_elem(std::move(other.m_elem)) {
    }

    // Copy assignment
    BetterVector& operator=(const BetterVector& other)
    {
        if (this == &other)
            return *this;

        m_sz = other.m_sz;
        m_elem = std::make_unique<double[]>(other.m_sz);
        std::copy(other.m_elem.get(), other.m_elem.get() + other.m_sz, m_elem.get());

        return *this;
    }

    // Move assignment
    BetterVector& operator=(BetterVector&& other) noexcept
    {
        if (this == &other)
            return *this;

        m_sz = std::exchange(other.m_sz, 0);
        m_elem = std::move(other.m_elem);

        return *this;
    }

    int           size() const noexcept { return m_sz; }
    double& operator[](int i) { return m_elem[i]; } // access to write
    const double& operator[](int i) const { return m_elem[i]; } // access to read

private:
    int m_sz;
    std::unique_ptr<double[]> m_elem;
};


void week1_day6()
{
    std::cout << "Rule of 0 / 3 / 5\n";
    /*
    BadVector v1(10);
    BadVector v2 = v1; // creates copy by bits meaning
    v1.m_elem == v2.m_elem; // - is the same


     * NOTE: if we do
        delete[] elem
        delete[] elem
        we get double delete → crash
     */

    std::cout << "\nRule of 3\n";
    std::cout << "1. destructor\n"
                 "2. copy constructor\n"
                 "3. copy assignment operator\n";

    std::cout << "\nRule of 5\n";
    std::cout << "1. destructor\n"
                 "2. copy constructor\n"
                 "3. copy assignment\n"
                 "4. move constructor\n"
                 "5. move assignment\n";

    std::cout << "\nRule of 0\n";
    std::cout << "Don't manage resources yourself. Use RAII classes\n";

    /* all is managed in std::vector
        no new
        no delete
        no destructor
        no copy
        no move
     */
    std::cout << "- std::vector\n"
                 "- std::string\n"
                 "- std::unique_ptr\n"
                 "- std::shared_ptr\n";
}

#endif //INC_3M_MARATHON_DAY6_H
