#pragma once

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
    int getHours();
    void setMinutes(int minutes);
    int getMinutes();
    void setSeconds(int seconds);
    int getSeconds();

    // public interface
    void reset();
    void increment();
    void print();
};
