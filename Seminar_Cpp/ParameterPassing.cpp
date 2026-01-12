
#include "Time.h"

#include <print>



// Call-by-Copy
void malZwei(int number)
{
    int tmp = number;
    tmp = tmp * 2;
    number = tmp;
}

void main_parameter_passing_01()
{
    int n = 5;
    std::println("n: {}", n);

    malZwei(n);

    std::println("n: {}", n);
}

// Call-by-Address
void malZweiByAddress(int* ip)
{
    //int tmp = number;
    //tmp = tmp * 2;
    //number = tmp;

    // Welcher Wert liegt hinter der Adresse :
    // Operator: Wert von:  * Operator
    // KAnn zum Lesen und Schreiben verwendet werden !!

    // Kürzer:

  //  *ip = *ip * 2;

    int tmp = *ip;
    tmp = tmp * 2;
    *ip = tmp;
}

void main_parameter_passing_02()
{
    int n = 5;
    std::println("n: {}", n);

    malZweiByAddress(&n);  // Übergabe eines Adresse: Adress-Operator &
                           // address of 

    std::println("n: {}", n);
}

// Call-by-Referenz
void malZweiByReferenz(int& number)
{
    int tmp = number;
    tmp = tmp * 2;
    number = tmp;
}

void main_parameter_passing_03()
{
    int n = 5;
    std::println("n: {}", n);

    malZweiByReferenz(n);  // Übergabe einer Referenz von n

    std::println("n: {}", n);
}

void main_pointer_vs_reference()
{
    int n = 5;

    int* ip = nullptr;   // pointer variable

    int& ri = n;         // reference variable   

    ip = &n;             // explizite Adressangabe

    // ACHTUNG:
    std::println("ip: {}", reinterpret_cast<intptr_t>(ip));
    std::println("ip: {}", *ip);
    std::println("ri: {}", ri);
    std::println();

    // ACHTUNG
    ++ip;
    ++ri;

    std::println("ip: {}", reinterpret_cast<intptr_t>(ip));
    std::println("ip: {}", *ip);  // FALSCH !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::println("ri: {}", ri);

    --ip;
    ++ri;

    std::println("ip: {}", reinterpret_cast<intptr_t>(ip));
    std::println("ip: {}", *ip);  // FALSCH !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::println("ri: {}", ri);
}

// printing address of a variable  
//static void test_09()
//{
//    int n = 123;
//    int* ip = &n;
//
//    std::println("&n: {:#X}", reinterpret_cast<intptr_t>(ip));
//    std::println("&n: {:#x}", reinterpret_cast<intptr_t>(&n));
//}


void main_parameter_passing_time()
{
    Time now(16, 15, 0);
    Time end(17, 0, 0);

    if (now.equals(end)) {
        std::println("gleich");
    }
    else {
        std::println("nicht gleich");
    }
}


void TueWasMitElementaremWertByCopy(int value)
{
    int m = value;
}


void TueWasMitElementaremWertByRef(const int& value)
{
    int m = value;
}

void main_parameter_passing_elementare_variable()
{
    int n = 123;

    TueWasMitElementaremWertByCopy(n);
    TueWasMitElementaremWertByRef(n);
}

void main_parameter_passing()
{
   // main_parameter_passing_01();
  //  main_parameter_passing_02();
  //    main_parameter_passing_03();

  //  main_pointer_vs_reference();
   // main_parameter_passing_time();
    main_parameter_passing_elementare_variable();
}

