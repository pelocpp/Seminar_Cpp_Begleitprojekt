
// Reihenfolge der Includes
// Empfehlung:
// a) benutzer-definierte Includes
// b) System-Includes

#include "Time.h"

#include <print>

// c'tors
Time::Time()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
    m_hours = hours;
    m_minutes = minutes;
    m_seconds = seconds;
}

// Constructor Chaining (auch in C# vorhanden)
Time::Time(int hours, int minutes) : Time (hours, minutes, 0)
{
}

void Time::reset()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

void Time::increment()
{
    m_seconds++;
    if (m_seconds >= 60)
    {
        m_seconds = 0;
        m_minutes++;
        if (m_minutes >= 60)
        {
            m_minutes = 0;
            m_hours++;
            if (m_hours >= 24)
            {
                m_hours = 0;
            }
        }
    }
}

void Time::print()
{
    std::println("{0:02}:{1:02}:{2:02}", m_hours, m_minutes, m_seconds);
}
