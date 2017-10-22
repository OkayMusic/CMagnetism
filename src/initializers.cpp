#include <iostream>
#include <vector>
#include <cmath>

#include <random>

#include "magnetism.h"

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
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 mersenne(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> uniform(0, PI);
    for (int i = 0; i < size; i++)
    {
        spinGrid[i] = uniform(mersenne);
    } 
    return spinGrid;
}

std::vector<double>
randomizeThetaComponent(std::vector<double> spinGrid)
{
    std::random_device rd;
    std::mt19937 gen(rd);
    std::uniform_real_distribution<> dis(0, 2 * PI);
    for (int i = 0; i < size; i++)
    {
        spinGrid[i] = dis(gen);
    }
    return spinGrid;
}

std::vector<std::vector<double>>
randomizePhiComponent(std::vector<std::vector<double>> spinGrid)
{
    std::random_device rd;
    std::mt19937 gen(rd);
    std::uniform_real_distribution<> dis(0, PI);
    short side = sqrt(size);
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            spinGrid[i][j] = dis(gen);
        }
    }
    return spinGrid;
}

std::vector<std::vector<double>>
randomizeThetaComponent(std::vector<std::vector<double>> spinGrid)
{
    std::random_device rd;
    std::mt19937 gen(rd);
    std::uniform_real_distribution<> dis(0, 2 * PI);
    short side = sqrt(size);
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            spinGrid[i][j] = dis(gen);
        }
    }
}