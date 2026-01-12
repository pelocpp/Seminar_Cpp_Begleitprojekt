#pragma once

class Time
{
private:
    // member data / instance variables
    int m_hours;
    int m_minutes;
    int m_seconds;

    // public interface / methods
    // Hier keine Implementierung
public:
    // c'tors
    Time();
    Time(int hours, int minutes, int seconds);
    Time(int hours, int minutes);

    void reset();
    void increment();
    void print();
};
