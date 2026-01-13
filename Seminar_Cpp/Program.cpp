#include "Time.h"

extern void main_test_operators();
extern void main_test_global_data();
extern void test_dynamic();
extern void test_big_data();
extern void main_test_frage();
extern void test_stl();

extern Time g_mittagsPause ;  // Zeile des Vertrauens :)  // Schwachstelle von C++

int main()
{
    test_stl();

    return 0;
}
