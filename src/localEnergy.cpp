#include <cmath>
#include <vector>
#include <iostream>

#include "magnetism.h"

namespace localEnergy
{
// 1D local exchange interaction
double exchange(int a, int b)
{
	double energy{ stiffConst * (
		pow((xComponent1D[a] - xComponent1D[b]), 2)
		+ pow((yComponent1D[a] - yComponent1D[b]), 2)
		+ pow((zComponent1D[a] - zComponent1D[b]), 2))};
	// std::cout << energy;
	return energy;
}
// 1D local Zeeman interaction
double zeeman(int a)
{
	return bField[0] * xComponent1D[a] + bField[1] * yComponent1D[a]
		+ bField[2] * zComponent1D[a];
}

// 1D local DM interaction
double dm(int a, int b)
{
	return dmConst * (-xComponent1D[a] * zComponent1D[b]
		+ zComponent1D[a] * xComponent1D[b]);
}

// this is the only function accessible from outside localEnergy.cpp
// this function sums the above functions, being careful about the boundaries
double energy(int a)
{
	// update the cartesian representation of the spin components
	double energy{0};
	energy += zeeman(a);
	if (a != 0)
	{
		energy += exchange(a-1, a) + dm(a-1, a);
	}
	else if (a != size - 1)
	{
		energy += exchange(a, a+1) + dm(a, a+1);
	}
	return energy;
}
}