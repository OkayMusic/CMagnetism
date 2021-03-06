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
		xComponent1D = make1DSpinGrid();
		yComponent1D = make1DSpinGrid();
		zComponent1D = make1DSpinGrid();
		thetaComponent1D = randomizeThetaComponent(thetaComponent1D);
		phiComponent1D = randomizePhiComponent(phiComponent1D);
	}
	case 2:
	{
		thetaComponent2D = make2DSpinGrid();
		phiComponent2D = make2DSpinGrid();
		xComponent2D = make2DSpinGrid();
		yComponent2D = make2DSpinGrid();
		zComponent2D = make2DSpinGrid();
		thetaComponent2D = randomizeThetaComponent(thetaComponent2D);
		phiComponent2D = randomizePhiComponent(phiComponent2D);
	}
	}
	sphericalToCartesian();

	int counter = 0;
	while (1)
	{
		reduceEnergy();		
		++counter;
		if (counter % (200000/size) == 0)
		{
			writeData();
			double energy = globalEnergy::energy();
			std::cout << energy << std::endl;
		}
	}


	std::getchar();
	return 0;
}