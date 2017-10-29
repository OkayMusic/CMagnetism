#include <vector>

short dimension = 1;
short boundary = 0;

int size = 10000;

double stiffConst = 1;
double dmConst = 0;
double surfConst = 0;
double temperature = 0;

std::vector<double> bField{0, 0, 1};

// for performance reasons, it is useful to prepare to store both spherical and
// cartesian components of the spins
std::vector<double> thetaComponent1D;
std::vector<double> phiComponent1D;
std::vector<double> xComponent1D;
std::vector<double> yComponent1D;
std::vector<double> zComponent1D;

std::vector<std::vector<double>> thetaComponent2D;
std::vector<std::vector<double>> phiComponent2D;
std::vector<std::vector<double>> xComponent2D;
std::vector<std::vector<double>> yComponent2D;
std::vector<std::vector<double>> zComponent2D;