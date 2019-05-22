#include<stdio.h>
#include<iostream>
//#include"stdafx.h"
using namespace std;

double param[10]={15,0,2,0,0,0,0,0,0};

// double checkpcs(double in){
//     int z=(int)in;
//     if(!z) return checkpcs(in*10);
//     else return in;
// }

// double checkwth(double in,double a,double b){
//     double wth=b-a;
//     printf("%llf",in);
//     in=checkpcs(in);
//     if(in<a) return checkwth(in+wth,a,b);
//     else if(in>b) return checkwth(in-wth,a,b);
//     else{
//         return in;
//     }
// }



// double result(int64 x){
//     double in=itod(x);
    
//     double sum=0;
//     for(int i=0;i<10;i++){
//         in=checkwth(in,-100,100);
//         sum+=param[i]*(pow(in,i));
//         cout<<sum<<endl;
//     }
    
//     return sum;
// }
int main(){
    int x,y;
    x=-1001;
    y=25;
    printf("%d\n",x%y);
}


