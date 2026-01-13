#include <iostream>

void test_dynamic_01()
{
    // allocating a single int variable
    int* pi = new int(123);                      // scalar new
    std::cout << *pi << std::endl;

    // releasing memory
    delete pi;
}


void test_dynamic_02()
{
    // allocating an array of int values
    int* pArray = new int[5];

    // initialize array
    for (int i = 0; i < 5; ++i) {

        //   pArray + i
        pArray[i] = i;  // In C++ kann man bei Adressen
                        // mit dem Index-operator arbeiten // wie in C#
    }

    // accessing dynamically allocated array
    for (int i = 0; i < 5; ++i) {
        std::cout << pArray[i] << ' ';
    }

    std::cout << std::endl;

    // releasing memory - note: array delete (!)
    delete[] pArray;
}

void test_dynamic_03()
{
    //char* cp = new char('A');
    //int* ip = new int(5);
    //double* dp = new double(1.0);

    char* cp = new char[5];   // Speicher: ja, Vorbelegung: NEIN
    int* ip = new int[5];
    double* dp = new double[5];

    //cp = cp + 1;  
   // *cp = '2';

    *(cp + 1) = '!';   // Adress-Arithmetik

    // Abkürzende Schreibweise - Identisch !!!

    cp[1] = '?';


    ip = ip + 1;
    dp = dp + 1;
}

class SimpleClass
{
public:
    SimpleClass() { std::cout << "c'tor" << std::endl; }

    void print() { std::cout << "print" << std::endl; }

    ~SimpleClass() { std::cout << "d'tor" << std::endl; }
};

 void test_dynamic_04()
 {
        // allocating a single variable
     SimpleClass * pSimpleClass = new SimpleClass();

     pSimpleClass->print();

         // releasing memory
     delete pSimpleClass;
}

 void test_dynamic_05()
 {
    // allocating and initializing an array of objects
    SimpleClass* pArray = new SimpleClass[5];

    // accessing dynamically allocated objects
    for (int i = 0; i < 5; ++i) {
        pArray[i].print();
    }

    // releasing memory - note: array delete (!)
    delete[] pArray;
 }




void test_dynamic()
{
    test_dynamic_05();
}