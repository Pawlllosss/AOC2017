#include <iostream>
#include <cmath>
#include "SpiralMem.h"

int main()
{
    int number_to_count;

    std::cin >> number_to_count;

    int tab_size = ceil(sqrt(number_to_count));

    SpiralMem tab( tab_size );

    std::cout<< tab.LookForPath( number_to_count ) << std::endl;

    return 0;
}
