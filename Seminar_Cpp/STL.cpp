#include <vector>
#include <print>
#include <deque>
#include <list>


void test_stl_01()
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

void test_stl_02()
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


void test_stl_03()
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


void test_stl_04()
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

void test_stl()
{
    test_stl_04();
}