#include "Time.h"

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

int main()
{
    // Stack
    Time now (10, 54, 0);     // first object // located on the stack
    //now.m_hours = 10;
    //now.m_minutes = 54;
    //now.m_seconds = 0;
    now.print();

    Time pause (12, 30, 0);   // second object // located on the stack
    //pause.m_hours = 12;
    //pause.m_minutes = 30;
    //pause.m_seconds = 0;
    pause.print();

    Time empty;
    empty.print();

    return 0;
}