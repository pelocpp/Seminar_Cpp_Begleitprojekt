#include "Time.h"

extern void main_test_operators();
extern void main_test_global_data();
extern void test_dynamic();

extern Time g_mittagsPause ;  // Zeile des Vertrauens :)  // Schwachstelle von C++

int main()
{
    test_dynamic();

    return 0;
}
