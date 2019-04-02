#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<stdlib.h>

using namespace std;

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
        sum+=param[i]*pow(x,i);
    }
    
    return sum;
}
//end function build

//crossover
double 