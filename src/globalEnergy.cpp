#include <vector>
#include "localEnergy.h"
#include "magnetism.h"

namespace globalEnergy
{
double energy(void)
{
    double energy{0};
    for (int i = 0; i < size; i++)
    {
        energy += localEnergy::energy(i);
    }
    return energy;
}
}