#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h> 
#include<windows.h>
#include<unistd.h>
using namespace std;





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
double math_func::result(int64 x){
    union{
        int64 a;
        double b;
    }in;
    in.a=x;
    int i=0;
    double sum=0;
    for(i=0;i<10;i++){
        sum+=param[i]*(pow(in.b,i));
    }
    
    return sum;
}
//end function build

indiv::indiv(int x){
    if (x==0)
    for(int i=0;i<100;i++){
        val[i]=rand64(GetTickCount());
    }
}

int64 indiv::show(int x){
    if(x>=100)return 0;
    return val[x];
}

void indiv::set(int64 value,int sub){
    val[sub]=value;
}




void showbits(int64 bit64){
    int64 temp=1;
    temp=temp<<63;
    for(int i=0;i<64;i++){
        if(temp&bit64){
            printf("1");
        }
        else{
            printf("0");
        }
        if((i+1)%8==0) printf(" ");
        temp=temp>>1;
    }
    printf("\n");
}




//crossover
void crossover(int64 indivA,int64 indivB,int64* newa,int64* newb){
    int64 nB,nA;
    int seed=(GetTickCount()*GetTickCount())%84992;
    int64 tmp0=rand64(seed);
    int64 rtmp0=~tmp0;
    // showbits(tmp0);
    nB=(indivA&tmp0)|(indivB&rtmp0);
    nA=(indivB&tmp0)|(indivA&rtmp0);
    *newa=nA;
    *newb=nB;
}

int64 rand64(int seed){
    int64 x[2];
    int pos=(GetTickCount()+seed)%84992;
    FILE* fp=fopen("random","r");
    if(fp==NULL){
        printf("Open Error\n");
        return 0;
    }
    fseek(fp,pos,SEEK_SET);
    fread(x,8,2,fp);
    fclose(fp);
    Sleep(10);
    return x[0]*x[1];
}

int64 mutation(int64 indiv){
    int64 x=rand64(GetTickCount());
    if(1&x){
        int64 temp=1<<(rand64(GetTickCount())%64);
        //printf("## 1 ##: ");
        showbits(temp);
        return (indiv|temp);
    }
    else{
        int64 temp=~(1<<(rand64(GetTickCount())%64));
        //printf("## 0 ##: ");
        showbits(temp);
        
        return (indiv&temp);
    }
}