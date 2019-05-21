#include<iostream>
#include<cmath>
#include<cstdlib> 
#include<ctime>
using namespace std;

double rand64(unsigned int seed);


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
void crossover(double indivA,double indivB,double* newa,double* newb){
    union indiv{
        int64 a;
        double b;
    };
    union indiv tmp,A,B,nA,nB;
    int seed=(time((time_t *)NULL)*time((time_t *)NULL))%84992;
    int64 tmp0=rand64(seed);
    int64 rtmp0=~tmp0;
    showbits(tmp0);
    A.b=indivA;
    B.b=indivB;
    nB.a=(A.a&tmp0)|(B.a&rtmp0);
    nA.a=(B.a&tmp0)|(A.a&rtmp0);
    *newa=nA.b;
    *newb=nB.b;
}

int64 rand64(int seed){
    int64 x[2];
    int pos=(time((time_t *)NULL)*time((time_t *)NULL)+seed)%84992;
    FILE* fp=fopen("random","r");
    if(fp==NULL){
        printf("Open Error\n");
        return 0;
    }
    fseek(fp,pos,SEEK_SET);
    fread(x,8,2,fp);
    fclose(fp);
    return x[0]*x[1];
}

int64 mutation(int64 indiv){
    int64 x=ran64(time((time_t*)NULL)*time((time_t*)NULL));
}