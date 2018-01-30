#include <iostream>
#include "SpiralMem.h"

int main()
{
    double number_to_count;

    std::cout<<"Input please: "<<std::endl;

    std::cin >> number_to_count;

    SpiralMem tab( number_to_count );

    std::cout<<tab.GetBiggerThanNumber()<<std::endl;

    return 0;
}
