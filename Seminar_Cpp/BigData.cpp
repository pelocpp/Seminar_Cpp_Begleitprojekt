// Definition einer Klasse in einem .cpp File

#include <print>
#include <vector>

class BigData
{
private:
    // private member data
    int m_size;                       // current number of elements
    int* m_data;                      // dynamically allocated array of elements
    std::vector<int> m_anotherData;   // Alternative mit der Bibliothek


public:
    // c'tor(s) / d'tor
    BigData();
    BigData(int size);

    BigData(const BigData&);    // copy-c'tor


    ~BigData();

    // operators
    BigData& operator= (const BigData& right);
};

// =======================================================
// Implementierung

BigData::BigData()
{
    m_data = nullptr;
    m_size = 0;
}

BigData::BigData(int size)
{
    m_data = new int[size];
    m_size = size;

    // Ohne STL Unterstützung
    for (int i = 0; i != size; ++i) {
        m_data[i] = 0;
    }
}


BigData::BigData(const BigData& other)    // copy-c'tor
{
    // allocate a new buffer for the current object
    m_data = new int[other.m_size];

    // copy other object to current object
    for (int i = 0; i != other.m_size; ++i) {
        m_data[i] = other.m_data[i];
    }

    // set size
    m_size = other.m_size;
}


BigData::~BigData()
{
    // std::println("d'tor");
    delete[] m_data;
}

//     bd2 = bd;

// operators
BigData& BigData::operator= (const BigData& right)
{
    if (this != &right) {

        // release at first left (current) object
        delete[] m_data;

        // allocate a new buffer for the right side
        m_data = new int[right.m_size];

        // copy right side to left (current) side
        for (int i = 0; i != right.m_size; ++i) {
            m_data[i] = right.m_data[i];
        }

        // adjust size
        m_size = right.m_size;
    }

    return *this;   // BigData&
}

// =======================================================
// Test

void test_big_data_01()
{
    BigData bd (10);
}


void test_big_data_02()
{
    BigData bd(10);

    BigData bd2(5);

  //  BigData bd3(5);

    bd2 = bd;  // Weil in bd, db2 ZEIGER sind, muss der operator=  EXPLIZIT implementiert werden.

    // C/C++: Gimmick: Mehrfachwertzuweisung

          // BigData: bd2, aber KEINE KOPIE: Eine Alias von bd2
    // bd3 = (bd2 = bd);

    // Suizid
  //  bd = bd;
}

void test_big_data_03()
{
    BigData bd(10);

    BigData bd2(bd);  // Geht das ???
}




void test_big_data()
{
    test_big_data_02();
}