#include<stdio.h>
#include"stdafx.h"
int main(){
	math_func a;
    union{
        int64 a;
        double b;
    }in;
    in.b=15.16;
    printf("%lf",a.result(in.a));
}


