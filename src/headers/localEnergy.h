#pragma once

// include file for localEnergy functions which should not be directly
// accessible from main

namespace localEnergy
{
double exchange(int a, int b);
double zeeman(int a);
double dm(int a, int b);
double energy(int a);
}