#include <iostream>
#include <math.h>
#include "function.h"

void function::getDegree()
{
    int d;
    std::cout << "degree:";
    std::cin >> d;
    degree = d;
    degreeDer = d - 1;
}

void function::printForm()
{
    std::cout << "f(x) = ";
    for (size_t i = 0; i < degree; i++) 
    {
        std::cout << symbols[i] << "x^" << degree - i << " + ";
    }
    std::cout << symbols[degree];
}

void function::getFactors()
{
    for (size_t i = 0; i < degree + 1; i++)
    {
        std::cout << "\n" << symbols[i] << " = ";
        std::cin >> factors[i];
    }
}

void function::initFactorsDer()
{
    for (size_t i = 0; i < degree + 1; i++)//if degree + 1 just to set last factor to 0 
    {
        if (i == degree)
        {
            factorsDer[i] = 0;
            break;
        }

        factorsDer[i] = factors[i] * (degree - i);
    }
}

void function::initDerivatives()
{
    for (size_t i = 1; i < degree; i++)
    {
        fDer[i]->degree = degree - i;
        initFactorsDer(fDer[i]);

    }
}

void function::initFactorsDer(function* f)
{
    f->degree = degreeDer;
    for (size_t i = 0; i < degree + 1; i++)
    {
        if (i == degree)
        {
            f->factorsDer[i] = 0;
            break;
        }

        f->factorsDer[i] = factors[i] * (degree - i);
    }
}

void function::getcurrX()
{
    std::cout << "where to start?:";
    std::cin >> currX;
}

long double function::getY(long double x)
{
    long double y = 0;
    for (size_t i = 0; i < degree + 1; i++)
    {
        if (degree - i == 0)
        {
            y += factors[i];
            break;
        }
        y += factors[i] * pow(x, degree - i);
    }
    return y;
}

long double function::getSlope(long double x)
{
    long double m = 0;
    for (size_t i = 0; i < degreeDer + 1; i++)
    {
        if (degreeDer - i == 0)
        {
            m += factorsDer[i];
            break;
        }
        m += factorsDer[i] * pow(x, degreeDer - i);
    }
    return m;
}

long double function::getSlopeYIntercept()
{
    return (getY(currX) - getSlope(currX) * currX);
}

long double function::getSlopeRoot()
{
    if (getSlope(currX) == 0)
        return -getSlopeYIntercept() / getSlope(currX + 0.5);
    return -getSlopeYIntercept() / getSlope(currX);
}

void function::updatecurrX()
{
    currX = getSlopeRoot();
}

long double function::getRoot()
{
    long double r;
    for (size_t i = 0; i < 100; i++)
    {
        r = getSlopeRoot();
        updatecurrX();
    }
    return r;
}

long double function::getRoot(function* f)
{
    long double r;
    for(size_t i = 0; i < 100; i++)
    {
        r = f->getSlopeRoot();
        f->updatecurrX();
    }

}


