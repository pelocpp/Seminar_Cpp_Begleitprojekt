#pragma once

#include <string>

class Time
{
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

    int getHours() { return m_hours; }
    int getMinutes() { return m_minutes; }
    int getSeconds() { return m_seconds; }

    // public interface
    void reset();
    void increment();
    void print();
};
