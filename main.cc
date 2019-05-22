#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stdafx.h"
//using namespace std;



int main(){
    printf("Please input the number of generations you want to simulate:\n");
    int N;
    scanf("%d",N);

    //input detection
    if(N<=0){
        printf("\nERROR! CHECK YOUR INPUT!");
        return 0;
    }


    //initialize initial population
    indiv Fath(0);
    indiv Chld();
    
    math_func func;
    for(int i=0;i<N;i++){

    }

}
