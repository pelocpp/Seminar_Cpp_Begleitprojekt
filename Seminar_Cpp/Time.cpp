
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

// Member Initializer List
//Time::Time(int hours, int minutes, int seconds) 
//    : m_hours (hours), m_minutes(minutes), m_seconds (seconds)
//{
//}



// Constructor Chaining (auch in C# vorhanden)
Time::Time(int hours, int minutes) : Time (hours, minutes, 0)
{
}

// getter/setter
void Time::setHours(int hours)
{
    if (hours >= 0 && hours < 24) {
        m_hours = hours;
    }
    else
    {
        std::println("Wrong value for hours: {}", hours);
    }
}

//void Time::setHours(int hours)
//{
//    //int dummy;
//    //this->dummy = 123;
//
//    this->hours = hours;
//}

//int Time::getHours()
//{
//    return m_hours;
//}

void Time::setMinutes(int minutes)
{
    if (minutes >= 0 && minutes < 60) {
        m_minutes = minutes;
    }
    else
    {
        std::println("Wrong value for hours: {}", minutes);
    }
}

//int Time::getMinutes()
//{
//    return m_minutes;
//}


void Time::setSeconds(int seconds)
{
    if (seconds >= 0 && seconds < 60) {
        m_seconds = seconds;
    }
    else
    {
        std::println("Wrong value for hours: {}", seconds);
    }
}

//
//int Time::getSeconds()
//{
//    return m_seconds;
//}



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
    std::println("{:02}:{:02}:{:02}", m_hours, m_minutes, m_seconds);
}

bool Time::equals(const Time& other) const  // eine Referenz ist ein Stellvertreter für ein Original
{                                // 'other' soll geschützt werden !!!
    // Test:
    //other.m_hours++;
    //m_hours++;

    if (m_hours != other.m_hours) {
        return false;
    }
    else if (m_minutes != other.m_minutes) {
        return false;
    }
    else if (m_seconds != other.m_seconds) {
        return false;
    }
    else {
        return true;
    }
}

bool Time::equalsAlternate(const Time& other) const  // eine Referenz ist ein Stellvertreter für ein Original
{                                               // 'other' soll geschützt werden !!!
    // Test:
    //other.m_hours++;
    //m_hours++;

    if (m_hours != other.getHours()) {
        return false;
    }
    else if (m_minutes != other.getMinutes()) {
        return false;
    }
    else if (m_seconds != other.getSeconds()) {
        return false;
    }
    else {
        return true;
    }
}

// ===========================================



//
//bool Time::operator == (const Time& other)
//{
//    if (m_hours != other.m_hours) {
//        return false;
//    }
//    else if (m_minutes != other.m_minutes) {
//        return false;
//    }
//    else if (m_seconds != other.m_seconds) {
//        return false;
//    }
//    else {
//        return true;
//    }
//}
//
//bool Time::operator != (const Time& other)
//{
//    return  ! (*this == other);
//}

bool operator == (const Time& left, const Time& right)
{
    if (left.m_hours != right.m_hours) {
        return false;
    }
    else if (left.m_minutes != right.m_minutes) {
        return false;
    }
    else if (left.m_seconds != right.m_seconds) {
        return false;
    }
    else {
        return true;
    }
}


//bool operator == (const Time& left, const Time& right)
//{
//    if (left.getHours() != right.getHours()) {
//        return false;
//    }
//    else if (left.getMinutes() != right.getMinutes()) {
//        return false;
//    }
//    else if (left.getSeconds() != right.getSeconds()) {
//        return false;
//    }
//    else {
//        return true;
//    }
//}

bool operator != (const Time& left, const Time& right)
{
    return ! (left == right);
}