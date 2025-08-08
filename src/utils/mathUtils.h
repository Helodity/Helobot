#pragma once

#include <cstdint>

extern int rngState;

int32_t generateGoodInt();
int linearCongruentialGenerator(int* state);
int32_t generateRandomInt(int32_t minimum, int32_t maximum);
float generateRandomFloat(float minimum, float maximum);
