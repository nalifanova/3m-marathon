#ifndef INC_3M_MARATHON_DAY6_H
#define INC_3M_MARATHON_DAY6_H

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


class BestVector
{
public:
    std::vector<double> m_data;
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
                 "3. copy assignment operator\n"
                 "4. move constructor\n"
                 "5. move assignment\n";

    /*
     * Example that can be replaced by `move`
     Vector(Vector&& other)
    {
        m_elem = other.m_elem;
        m_sz = other.m_sz;

        other.m_elem = nullptr;
        other.m_sz = 0;
    }
     */
    std::cout << "\nRule of 0\n";
    std::cout << "Don't manage memory yourself\n";

    /* all is managed in std::vector
        no new
        no delete
        no destructor
        no copy
        no move
     */
}

#endif //INC_3M_MARATHON_DAY6_H
