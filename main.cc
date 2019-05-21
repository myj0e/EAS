#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stdafx.h"
//using namespace std;


// int64_t rand64(int seed){
//     int64_t x[2];
//     FILE* fp=fopen("random","r");
//     if(fp==NULL){
//         printf("Open Error\n");
//         return 0;
//     }
//     fseek(fp,seed,SEEK_SET);
//     fread(x,8,2,fp);
    
//     fclose(fp);
//     return x[0]*x[1];
// }


// //crossover
// void crossover(double indivA,double indivB,double* newa,double* newb){
//     union indiv{
//         int64_t a;
//         double b;
//     };
//     union indiv tmp,A,B,nA,nB;
//     int seed=(time((time_t *)NULL)*time((time_t *)NULL))%84992;
//     int64_t tmp0=rand64(seed);
// //debug
//     printf("crossover tmp:");
//     showbits(tmp0);
//     int64_t rtmp0=~tmp0;
//     A.b=indivA;
//     B.b=indivB;
//     nB.a=(A.a&tmp0)|(B.a&rtmp0);
//     nA.a=(B.a&tmp0)|(A.a&rtmp0);
//     *newa=nA.b;
//     *newb=nB.b;
// }

int main(){
    union test{
        int64 a;
        double b;
    };
    int64 x,y;
    union test A;
    union test B;
    union test nB;
    union test nA;;
    A.a=rand64(666);
    B.a=rand64(118);
    showbits(A.a);
    showbits(B.a);
    crossover(A.b,B.b,&nA.b,&nB.b);
    showbits(nA.a);
    showbits(nB.a);
}
