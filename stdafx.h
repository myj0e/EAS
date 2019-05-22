#ifndef STDAFX_H
#define STDAFX_H


typedef unsigned long long int64;



void crossover(int64 indivA,int64 indivB,int64* newa,int64* newb);
int64 rand64(int seed);
void showbits(int64 bit64);
int64 mutation(int64 indiv);


//function class
class math_func
{
private:
    double param[10];    
public:
    math_func();
    double result(int64 x);
};


class indiv{
private:
    int64 val[100]={0};
public:
    indiv(int x=1);
    int64 show(int x);
    void set(int64 value,int sub);
};



#include"stdafx.cc"

#endif