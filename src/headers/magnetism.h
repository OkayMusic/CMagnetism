#pragma once
#include <vector>

const double PI = 3.141592653589793238463;

extern short dimension;
extern short boundary;

extern int size;

extern double stiffConst;
extern double dmConst;
extern double surfConst;
extern double temperature;

extern std::vector<double> bField;

extern std::vector<double> thetaComponent1D;
extern std::vector<double> phiComponent1D;
extern std::vector<double> xComponent1D;
extern std::vector<double> yComponent1D;
extern std::vector<double> zComponent1D;

extern std::vector<std::vector<double>> thetaComponent2D;
extern std::vector<std::vector<double>> phiComponent2D;
extern std::vector<std::vector<double>> xComponent2D;
extern std::vector<std::vector<double>> yComponnt2D;
extern std::vector<std::vector<double>> zComponent2D;


std::vector<double> make1DSpinGrid(void);
std::vector<std::vector<double>> make2DSpinGrid(void);

std::vector<double>
randomizePhiComponent(std::vector<double> spinGrid);

std::vector<double>
randomizeThetaComponent(std::vector<double> spinGrid);
std::vector<std::vector<double>>
randomizePhiComponent(std::vector<std::vector<double>> spinGrid);
std::vector<std::vector<double>>
randomizeThetaComponent(std::vector<std::vector<double>> spinGrid);
std::vector<std::vector<double>>
randomizePhiComponent(std::vector<std::vector<double>> spinGrid);
