


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

void main_parameter_passing()
{
   // main_parameter_passing_01();
  //  main_parameter_passing_02();
    main_parameter_passing_03();
}

