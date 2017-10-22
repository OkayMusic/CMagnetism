#include <iostream>
#include <vector>
#include "magnetism.h"

int main(void)
{
    // firstly, initialize the spin grids in appropriate dimension
    switch (dimension)
    {
    case 1:
    {
        thetaComponent1D = make1DSpinGrid();
        phiComponent1D = make1DSpinGrid();
        thetaComponent1D = randomizeThetaComponent(thetaComponent1D);
        for (int i = 0; i < size; i++){
            std::cout << thetaComponent1D[i] << std::endl;
        }
    }
    case 2:
    {
        thetaComponent2D = make2DSpinGrid();
        phiComponent2D = make2DSpinGrid();
    }
    }

    // before running the simulation, randomize the spin orientations
    // thetaComponent = randomizeThetaComponent(thetaComponent);


    return 0;
}