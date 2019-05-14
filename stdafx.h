#ifndef STDAFX_H
#define STDAFX_H

#include"u8.h"
//function class
class math_func
{
private:
    double param[10];    
public:
    math_func();
    double result(double x);
};


//crossover
void crossver(double indivA,double indivB,double& newa,double& newb);


#endif