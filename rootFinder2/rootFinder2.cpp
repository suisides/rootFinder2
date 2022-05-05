#include <iostream>
#include "function.h"

int main()
{
    while (true) 
    {
        function F;

        F.getDegree();
        F.printForm();
        F.getFactors();
        F.initFactorsDer();
        F.getcurrX();
        std::cout << "Root: " << F.getRoot() << "\n\n"; // perfection
    }
}
