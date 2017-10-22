#include <cmath>
#include <vector>
#include "magnetism.h"

namespace localEnergy
{
// 1D exchange interaction
double exchange(int a)
{
    if (a == 0){
        return stiffConst*(
            pow(xComponent1D[0] - xComponent1D[1], 2)
            + pow(yComponent1D[0] - yComponent1D[1], 2)
            + pow(zComponent1D[0] - zComponent1D[1], 2));
    }else if (a == size){
        return stiffConst*(
            pow(xComponent1D[size-1] - xComponent1D[size], 2)
            + pow(yComponent1D[size-1] - yComponent1D[size], 2)
            + pow(zComponent1D[size-1] - zComponent1D[size], 2));
    }else{
        return stiffConst*(
            pow(xComponent1D[a-1] - xComponent1D[a], 2)
            + pow(xComponent1D[a] - xComponent1D[a+1], 2)
            + pow(yComponent1D[a-1] - yComponent1D[a], 2)
            + pow(yComponent1D[a] - yComponent1D[a+1], 2)
            + pow(zComponent1D[a-1] - zComponent1D[a], 2)
            + pow(zComponent1D[a] - zComponent1D[a+1], 2)
        );
    }
}
}