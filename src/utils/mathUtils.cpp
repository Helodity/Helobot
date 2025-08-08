#include <array>
#include "mathUtils.h"
#include <chrono>


//Christ.
int32_t rngState = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count();

int32_t linearCongruentialGenerator(int32_t* state) {
    int result = ((*state * 1103515245U) + 12345U) & 0x7fffffff;
    *state = result;
    return result;
}

int32_t generateGoodInt() {
    //Let's generate two, get their top 16 bits, and merge them.
    //This is because relying on the least significant bits of an LCG is
    //a bad idea (for instance, the numbers always come out alternating
    //between odd and even).
    int32_t n1 = linearCongruentialGenerator(&rngState);
    int32_t n2 = linearCongruentialGenerator(&rngState);
    
    int32_t msb1 = (n1 >> 16) & 0xFFFF;
    int32_t msb2 = (n2 >> 16) & 0xFFFF;
    
    return ((int32_t) msb1 << 16) | msb2;
}

int32_t generateRandomInt(int32_t minimum, int32_t maximum) {
    if(minimum == maximum) return minimum;
    if(minimum > maximum) std::swap(minimum, maximum);
    
    if(minimum == maximum) return minimum;
    if(minimum > maximum) std::swap(minimum, maximum);
    return
        (
            (generateGoodInt()) %
            (maximum - minimum + 1)
        ) + minimum;
}

float generateRandomFloat(float minimum, float maximum) {
    if(minimum == maximum) return minimum;
    if(minimum > maximum) std::swap(minimum, maximum);
    
    return
        (float) generateGoodInt() /
        ((float) INT32_MAX / (maximum - minimum)) + minimum;
}