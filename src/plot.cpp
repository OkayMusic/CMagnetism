#include <iostream>
#include <fstream>
#include <cstdlib>
#include "magnetism.h"

void printToPlot(void)
{
    std::ofstream outf("datameems.txt");

    if (!outf)
    {
        std::cout << "couldn't open file for writing";
        exit(1);
    }

    for (int i = 0; i < size; ++i)
    {
        // outf << xComponent1D[i] << " " 
        // << yComponent1D[i] << " " 
        // << zComponent1D[i] << std::endl;
        outf << "greetings" << std::endl;
    }
    outf.close();
}