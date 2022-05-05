#include <iostream>
#include "function.h"

int main()
{
    while (true) 
    {
        function F;
        function FDer;
        

        F.getDegree();
        F.printForm();
        F.getFactors();
        F.initFactorsDer(&FDer);
        F.getcurrX();
        std::cout << "Root: " << F.getRoot() << "\n\n"; // perfection
    }
}
