#include "Time.h"

#include <print>

extern void main_parameter_passing();

Time g_mittagsPause(12, 30, 0);

// Vergleich

#if 0

int main_on_the_stack()
{
    // Stack
    Time now;     // first object // located on the stack
    now.m_hours = 11;
    now.m_minutes = 54;
    now.m_seconds = 0;
    now.print();

    Time pause;   // second object // located on the stack
    pause.m_hours = 12;
    pause.m_minutes = 30;
    pause.m_seconds = 0;
    pause.print();

    return 0;
}

int main_on_the_heap()
{
    // Heap
    Time* now = new Time();     // first object // located on the heap
    now->m_hours = 11;
    now->m_minutes = 58;
    now->m_seconds = 30;
    now->print();

    Time* pause = new Time();   // second object // located on the heap
    pause->m_hours = 12;
    pause->m_minutes = 30;
    pause->m_seconds = 0;
    pause->print();

    delete now;                 // release object
    delete pause;               // release object

    return 0;
}

#endif

// =============================================

int main_getting_started()
{
    // Stack
    Time now(10, 54, 0);     // first object // located on the stack
    now.print();

    Time pause(12, 30, 0);   // second object // located on the stack
    pause.print();

    Time empty;
    empty.print();

    //now.m_hours = 13;
    //now.m_minutes = 31;

    now.setHours(9999);
    int currentHours = now.getHours();
    now.print();

    return 0;
}

// =============================================

// free function // not a method

void workingOnATimeObject(Time t)
{
    int hours = t.getHours();
  //  std::println("Hours: {}", hours);

    t.setHours(hours + 1);
    t.print();
}


int main_demo()
{
    // Stack
    Time now(14, 30, 0);
    now.print();

    workingOnATimeObject(now);
    now.print();  // <===============

    return 0;
}


// =============================================

void main_test_operators()
{
    Time now (14, 30, 0);
    Time than(14, 35, 0);

    bool b = now.equals(than);

    b = (now == than);    // InFix-Notationen  // Operator-Style
    b = (now != than);

    // Ironisch , nur zum Spaß

    // b = now.operator== (than);

    b = operator== (now, than);  // Method-Style
}

void main_test_frage()
{
    Time t(12, 0, 0);

    Time t2;

    t2 = t;   // Geht das in C++

    // Noch eine Frage

    Time t3(t); // Geht das in C++: Ja, Kopier-Konstruktor

    // STOLPERFALLE: Arghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
    Time t4 = t;                   // Kopier-Konstruktor: 2. Schreibweise
}


void main_test_global_data()
{
    g_mittagsPause.print();
}