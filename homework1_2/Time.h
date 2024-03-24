#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;
using std::setfill;


constexpr unsigned SECONDS_IN_HOURS = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;

class Time
{
private:
    unsigned secondsFromMidnight;

    bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldVlaue, unsigned multiplier);

public:

    Time();
    Time(unsigned hours, unsigned mins, unsigned seconds);
    unsigned getHours() const;
    unsigned getMins() const;

    unsigned getSeconds() const;
    bool setHours(unsigned hours);

    bool setMins(unsigned mins);
    bool setSeconds(unsigned seconds);

    unsigned getSecondFromMidnight() const;
    void tick();
    void serialize(std::ostream& os) const;

};