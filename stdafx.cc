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
    while(x!=3){
        cout<<"Please input the parameter of X^"<<x<<" (default:0)"<<endl;
        cin>>param[x];
        x++;
    }
    cout<<"Please input your data boundary"<<endl;
    cout<<"min:";
    cin>>a;
    cout<<"max:";
    cin>>b;
    if(a>b){
        printf("Error!Input error!\n");
    }
    cout<<endl;
}



//return function result
double math_func::result(int64 x){
    double in=itod(x);
    double sum=0;
    for(int i=0;i<10;i++){
        sum+=param[i]*(pow(in,i));
    }
    
    return sum;
}
//end function build

indiv::indiv(int x,math_func func){
    if (x==0)
    for(int i=0;i<100;i++){
        int64 ran=rand64(GetTickCount());
        //showbits(ran);
        val[i]=dtoi(checkwth(itod(ran),func.a,func.b));
        //showbits(dtoi(val[i]));
        //printf("\n");
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

void showbits_rt(int64 bit64){
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
    printf("\r");
}



//crossover
void math_func::crossover(int64 indivA,int64 indivB,int64* newa,int64* newb){
    int64 nB,nA;
    int seed=(GetTickCount())%84992;
    
    int64 tmp0=rand64(seed);
    int64 rtmp0=~tmp0;
    //showbits(indivA);
    nB=(indivA&tmp0)|(indivB&rtmp0);
    nA=(indivB&tmp0)|(indivA&rtmp0);
    //showbits(nA);
    double newA=checkwth(itod(nA),a,b);
    //printf("pass0\n");
    double newB=checkwth(itod(nB),a,b);
    *newa=dtoi(newA);
    
    *newb=dtoi(newB);
}

int64 math_func::mutation(int64 indiv){
    int64 x=rand64(GetTickCount());
    if(1&x){
        int64 temp=1<<(rand64(GetTickCount())%64);
        //printf("## 1 ##: ");
        //showbits(temp);
        x=(indiv|temp);
    }
    else{
        int64 temp=~(1<<(rand64(GetTickCount())%64));
        //printf("## 0 ##: ");
        //showbits(temp);
        
        x=(indiv&temp);
    }
    return dtoi(checkwth(itod(x),a,b));
}



int64 rand64(int seed){
    int64 x[2];
    int pos=(GetTickCount()*GetTickCount()+seed)%84992;
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




union{
    int64 a;
    double b;
}OUT_PUT;
double itod(int64 in){
    OUT_PUT.a=in;
    return OUT_PUT.b;
}
int64 dtoi(double in){
    OUT_PUT.b=in;
    return OUT_PUT.a;
}

double checkpcs(double in){
    int z=(int)100*in;
    if(!z) return checkpcs(in*10);
    else return in;
}

double checkwth(double in,double a,double b){
    double wth=b-a;
    int zin=(int)in;
    int zwth=(int)wth;
    in=in-zin;
    //printf("%llf\n",in);
    
    in=checkpcs(in);
    if(!zwth)zin=zin%zwth;
    in=(double)zin+in;
    //showbits(dtoi(in));
    return in;
}
