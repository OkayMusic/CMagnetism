#include <vector>

const double PI = 3.141592653589793238463;

short dimension = 1;
short boundary = 0;

int size = 30 * 30;

double stiffConst = 0;
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