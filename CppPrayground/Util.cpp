#include <stdlib.h>
#include <random>

#include "Util.h"

bool Util::Chance50(void) {
    static std::random_device rd;  
    static std::mt19937 gen(rd());
    static std::bernoulli_distribution d(0.5);

    return d(gen);
}

int Util::RandomRangeInt(int min, int max) {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(min, max);

    return distr(gen);
}
