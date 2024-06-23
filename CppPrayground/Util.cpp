#include <stdlib.h>
#include <random>

#include "Util.h"

// NOTE: I'm quite unsure of this solution. I don't think it is actually 50%
// since it's not uniform and uses the std C lib
bool Util::Chance50() {
    return rand() % 2;
}

int Util::RandomRangeInt(int min, int max) {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(min, max);

    return distr(gen);
}
