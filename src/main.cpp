#include <iostream>
#include <chrono>
#include "TimeCounter.h"

int main()
{
    START_COUNT_TIME;
    std::cout << "hello world" << std::endl;
    return 0;
}
