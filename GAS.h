#ifndef STDAFX_H
#define STDAFX_H


typedef unsigned long long int64;



void crossover(int64 indivA,int64 indivB,int64* newa,int64* newb);
int64 rand64(int seed);
void showbits(int64 bit64);
int64 mutation(int64 indiv);
double itod(int64 in);
int64 dtoi(double in);
double checkpcs(double in);
double checkwth(double in,double a,double b);



//function class
class math_func
{
private:
    double param[10]={0};
  
public:
    double a;
    double b;  
    math_func();
    double result(int64 x);
    int64 mutation(int64 indiv);
    void crossover(int64 indivA,int64 indivB,int64* newa,int64* newb);
};


class indiv{
private:
    int64 val[100]={0};
public:
    indiv(int x,math_func func);
    int64 show(int x);
    void set(int64 value,int sub);
};



#include"GAS.cc"

#endif