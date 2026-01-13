#pragma once

#include <string>

class Time
{
    // friendship
    friend bool operator == (const Time& left, const Time& right);
    friend bool operator != (const Time& left, const Time& right);

private:
    // member data / instance variables
    int m_hours;
    int m_minutes;
    int m_seconds;

    std::string m_locale;  // Zeitzone

    // int _hours;   // Stilistik C# // Instanzvariable // Membervariable

    // public interface / methods
    // Hier keine Implementierung
public:
    // c'tors
    Time();
    Time(int hours, int minutes, int seconds);
    Time(int hours, int minutes);

    // getter / setter
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    int getHours() const { return m_hours; }
    int getMinutes() const { return m_minutes; }
    int getSeconds() const { return m_seconds; }

    // public interface
    void reset();
    void increment();
    void print();

    // comparison
    bool equals (const Time& other) const;
    bool equalsAlternate(const Time& other) const;

    // operators

    //bool operator == (const Time& other);

    //bool operator != (const Time& other);

};

// global function
//extern bool operator == (const Time& left, const Time& right);
//extern bool operator != (const Time& left, const Time& right);
