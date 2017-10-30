#include <fstream>
#include <iostream>
#include <cstdlib>

#include "magnetism.h"

void writeData(void)
{
    std::ofstream dataFile("build/dataFile.dat", std::ios::trunc);

    if (!dataFile.is_open())
    {
        std::cout << "failed to open file";
        exit(1);
    }

    dataFile << "Mx My Mz:" << std::endl;

    for (int i = 0; i < size; ++i)
    {
        dataFile << xComponent1D[i] << " "
        << yComponent1D[i] << " " 
        << zComponent1D[i] << std::endl;
    }
}