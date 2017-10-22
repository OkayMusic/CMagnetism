#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#include "magnetism.h"

// initialize mersenne twister PRNG:
// first seed mersenne twister with entropic noise 
// the mersenne twister will generate big random integers
// std::uniform_real_distribution converts the ints to doubles in our 
// desired interval
std::random_device mTwistSeed;        
std::mt19937 mersenne(mTwistSeed());

std::vector<double>
make1DSpinGrid(void)
{
    std::vector<double> spins;
    spins.resize(size);
    return spins;
}

std::vector<std::vector<double>>
make2DSpinGrid(void)
{
    short side = std::sqrt(size);
    std::vector<std::vector<double>> spins;
    spins.resize(side);
    for (int i = 0; i < side; i++)
    {
        spins[i].resize(side);
    }
    return spins;
}

// returns spin grid with randomized phi component
std::vector<double>
randomizePhiComponent(std::vector<double> spinGrid)
{
    std::uniform_real_distribution<> uniform(0, 2*PI);
    for (int i = 0; i < size; i++)
    {
        spinGrid[i] = uniform(mersenne);
    } 
    return spinGrid;
}

std::vector<double>
randomizeThetaComponent(std::vector<double> spinGrid)
{
    std::uniform_real_distribution<> uniform(0, PI);
    for (int i = 0; i < size; i++)
    {
        spinGrid[i] = uniform(mersenne);
    }
    return spinGrid;
}

std::vector<std::vector<double>>
randomizePhiComponent(std::vector<std::vector<double>> spinGrid)
{
    std::uniform_real_distribution<> uniform(0, 2*PI);
    short side = sqrt(size);
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            spinGrid[i][j] = uniform(mersenne);
        }
    }
    return spinGrid;
}

std::vector<std::vector<double>>
randomizeThetaComponent(std::vector<std::vector<double>> spinGrid)
{
    std::uniform_real_distribution<> uniform(0, PI);
    short side = sqrt(size);
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            spinGrid[i][j] = uniform(mersenne);
        }
    }
}

void sphericalToCartesian(void)
{
    switch (dimension){
        case 1:
        for (int i = 0; i < size; i++)
        {
            xComponent1D[i] = sin(thetaComponent1D[i]) * cos(phiComponent1D[i]);
            yComponent1D[i] = sin(thetaComponent1D[i]) * sin(phiComponent1D[i]);
            zComponent1D[i] = cos(thetaComponent1D[i]);
        }
    }
}