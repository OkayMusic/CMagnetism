#include <vector>
#include <random>
#include <cmath>
#include <iostream>

#include "localEnergy.h"
#include "magnetism.h"

std::uniform_real_distribution<> thetaDist(-PI/2, PI/2);
std::uniform_real_distribution<> phiDist(-PI, PI);
double testEnergy{0};
// kicks a spin at site randSite and checks to see if the kick reduced energy
void wiggle(int randSite)
{
    double dPhi = phiDist(mersenne);
    double dTheta = thetaDist(mersenne);

    double initialEnergy = localEnergy::energy(randSite);
    double initialPhi = phiComponent1D[randSite];
    double initialTheta = thetaComponent1D[randSite];

    // now kick the spin at site randSite by dPhi, dTheta
    phiComponent1D[randSite] += dPhi;
    thetaComponent1D[randSite] += dTheta;

    sphericalToCartesian(randSite);
    double newEnergy = localEnergy::energy(randSite);

    // if the new configuration is higher in energy, revert configuration
    if (newEnergy > initialEnergy)
    {
        phiComponent1D[randSite] = initialPhi;
        thetaComponent1D[randSite] = initialTheta;
        
        sphericalToCartesian(randSite);
    }
}

// crude! call wiggle on random sites to constantly lower system energy
void reduceEnergy(void)
{
    std::uniform_int_distribution<> siteDist(0, size-1);
    for (int i = 0; i < size; i++)
    {
        wiggle(siteDist(mersenne));
    }
}
