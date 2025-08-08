#pragma once

#include <vector>

template <typename T> 
T getRandomFromList(std::vector<T> inList){
    return inList.at(generateRandomInt(0, inList.size() - 1));
};