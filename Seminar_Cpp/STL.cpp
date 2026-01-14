#include <vector>
#include <print>
#include <deque>
#include <list>
#include <algorithm>

static void test_stl_01()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    // non perfect
    for (int i = 0; i != numbers.size(); ++i) {

        int value = numbers[i];   // Der Index ist problematisch
        std::println("{}: {}", i, value);
    }
}

static void test_stl_02()
{
    std::vector<int> numbers;

    numbers.reserve(80);   // <================ Capacity

    for (int i = 0; i != 100; ++i) {

        numbers.push_back(2 * i);
        std::println("{}: Size: {} == Capacity: {}", i, numbers.size(), numbers.capacity());
    }

    numbers.shrink_to_fit();

    std::println("Size: {} == Capacity: {}", numbers.size(), numbers.capacity());
}


static void test_stl_03()
{
   // std::vector<int> numbers;
    // std::deque<int> numbers;
    std::list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    // Iteratoren

   // std::vector<int>::iterator anfang = numbers.begin();
    //std::deque<int>::iterator anfang = numbers.begin();      // Upps Transparency ????
    std::list<int>::iterator anfang = numbers.begin();      // Upps Transparency ????

  //  auto anfang = numbers.begin();      // Upps Transparency ???? // C++ 11 


    if (anfang == numbers.end()) {
        std::println(" Done.");
        return;
    }



    int value = *anfang;
    std::println(" ==> {}", value);

    anfang++;
    if (anfang == numbers.end()) {
        std::println(" Done.");
        return;
    }
    value = *anfang;
    std::println(" ==> {}", value);

    anfang++;
    if (anfang == numbers.end()) {
        std::println(" Done.");
        return;
    }
    value = *anfang;
    std::println(" ==> {}", value);

    anfang++;
    if (anfang == numbers.end()) {
        std::println(" Done.");
        return;
    }
    value = *anfang;
    std::println(" ==> {}", value);

}


static void test_stl_04()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    std::vector<int>::iterator pos = numbers.begin();
    std::vector<int>::iterator end = numbers.end();

    while (pos != end) {

        std::println(" ==> {}", *pos);
        pos++;
    }
}


static void test_stl_04_A()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    auto pos = numbers.begin();
    auto end = numbers.end();

    while (pos != end) {

        std::println(" ==> {}", *pos);
        pos++;
    }
}



static void print(int value)
{
    std::println(" ==> {}", value);
}

static void test_stl_05()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);

    // Funktion:  std::for_each 

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );
}

static void test_stl_06()
{
    std::vector<int> numbers;

    numbers.resize(50);

    // Vorbelegung
    // Ohne STL Unterstützung
    //for (int i = 0; i != size; ++i) {
    //    m_data[i] = 0;
    //}

    std::fill(
        numbers.begin(),
        numbers.end(),
        123
    );
}


static int init()
{
    // return 456;
    static int value = 1;    // value has global state, but is only visible inside function 'init'
    value += 2;
    return value;
}

static void test_stl_07()
{
    std::vector<int> numbers;

    numbers.resize(50);

    std::generate(
        numbers.begin(),
        numbers.end(),
        init
    );
}

// =======================================================

class Printer
{
public:
    int operator() (int value) {
        return 2 * value;
    }
};

static void test_stl_08()
{
    Printer myPrinter;

    int result = myPrinter(10);
}


class FormattedPrinter
{
private:
    std::string m_header;

public:
    FormattedPrinter() {
        m_header = ">>> ";
    }

    FormattedPrinter(const std::string& header) {
        m_header = header;
    }

    void operator() (int value) {
        std::println("{} {}", m_header, value);
    }
};

static void test_stl_09()
{
    std::vector<int> numbers;
    numbers.resize(10);

    std::fill(
        numbers.begin(),
        numbers.end(),
        123
    );

    FormattedPrinter myPrinter ("========>   ");

    std::for_each(
        numbers.begin(),
        numbers.end(),
        myPrinter
    );
}


void test_stl()
{
    test_stl_09();
}