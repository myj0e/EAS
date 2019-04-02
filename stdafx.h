#ifndef STDAFX_H
#define STDAFX_H

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
double crossver(double* indivA,double* indivB);


#endif