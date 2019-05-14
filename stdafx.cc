#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

u64 rand64(unsigned int seed);


// typedef struct parameter
// {
//     int number;
//     double x=0;
//     parameter* next=NULL;
// };


//define a class, linked list & functions:init parameters;
// class math_func
// {
// private:
//     double param[10];    
// public:
//     math_func();
//     double result(double x);
// };

//init functions
math_func::math_func(){
    int x=0;
    while(x!=10){
        cout<<"Please input the parameter of X^"<<x<<" (default:0)"<<endl;
        cin>>param[x];
        x++;
    }
}

//return function result
double math_func::result(double x){
    int i=0;
    double sum=0;
    for(i=0;i<10;i++){
        sum+=param[i]*(pow(x,i));
    }
    
    return sum;
}
//end function build

//crossover
void crossver(double indivA,double indivB,double& newa,double& newb){
    u64 templet=rand64(time((time_t *)NULL));
    u64 a2b=(u64)indivA&templet;
    u64 b2a=(u64)indivB&templet;
    u64 a=(u64)indivA&(~templet);
    u64 b=(u64)indivB&(~templet);
    newa=(double)(a2b|b);
    newb=(double)(b2a|a);
}

u64 rand64(unsigned int seed){
    u64 uu64;
    srand(time((time_t *)NULL)*(17+seed));
    uu64.a=rand();
    srand(time((time_t *)NULL)*(34+seed));
    uu64.b=rand();
    srand(time((time_t *)NULL)*(51+seed));
    uu64.c=rand();
    srand(time((time_t *)NULL)*(68+seed));
    uu64.d=rand();
    return uu64;

}