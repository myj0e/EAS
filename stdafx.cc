#include"stdafx.h"
#include<iostream>
#include<cmath>

using namespace std;

typedef struct parameter
{
    int number;
    double x=0;
    parameter* next=NULL;
};


//define a class, linked list & functions:init parameters;
class math_func
{
private:
    parameter* head;    
public:
    math_func();
    double result(double x);
};

//init functions
math_func::math_func(){
    int x=0;
    double param;
    parameter* s;
    parameter* l;
    while(x!=10){
        cout<<"Please input the parameter of X^"<<x<<" (default:0)"<<endl;
        cin>>param;
        s=(parameter*)malloc(sizeof(parameter));
        s->number=param;
        s->x=x;
        l=head->next;
        head->next=s;
        s->next=l;
        x++;
    }
}

//return function result
double math_func::result(double x){
    parameter* s=head;
    double sum=0;
    while(s){
        sum+=s->number*pow(x,s->x);
        s=s->next;
    }
    return sum;
}
//end function build

double 