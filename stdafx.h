#ifndef STDAFX_H
#define STDAFX_H


typedef unsigned long long int64;

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
void crossover(double indivA,double indivB,double* newa,double* newb);
int64 rand64(int seed);
void showbits(int64 bit64);

#include"stdafx.cc"

#endif