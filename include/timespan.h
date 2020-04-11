#ifndef _TIMESPAN_H_
#define _TIMESPAN_H_

#include "wave.h"
#include <vector>

class Timespan {
private:
    std::vector<float> samples;
    int32_t sample_rate;
    int32_t millis;

public:
    Timespan() = default;
    Timespan(int32_t millis, int32_t sample_rate);
    Timespan(const char *filename, int32_t sample_rate);
    void save(const char *filename) const;
    void apply(const Wave& wave);
    void saveWAV(const char *filename) const;
    int32_t get_sample_rate() const;
};

#endif