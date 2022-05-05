#pragma once
class function
{
public:
	long double currX;
	int degree;
	int degreeDer;
	char symbols[12]{"abcdefghijk"};
	long double factors[12] = { 0 }; 
	long double factorsDer[12] = { 0 };
	
	function* fDer[12];
	
	void getDegree();
	void printForm();
	void getFactors();
	void initDerivatives();
	void initFactorsDer();
	void initFactorsDer(function* f);
	void getcurrX();
	long double getY(long double x);
	long double getSlope(long double x);
	long double getSlopeYIntercept();
	long double getSlopeRoot();
	void updatecurrX();

	long double getRoot();
	long double getRoot(function* f);
};

