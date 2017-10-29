#include <vector>
#include <iostream>
#include "localEnergy.h"
#include "magnetism.h"

namespace globalEnergy
{
double energy(void)
{
    double energy{0};
    for (int i = 0; i < size; i++)
    {
        double siteEnergy = localEnergy::energy(i);
        energy += siteEnergy;
    }
    std::cout << energy << std::endl;
    return energy;
}
}