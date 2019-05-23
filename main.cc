#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"GAS.h"
//using namespace std;



int main(){
    printf("Please input the number of generations you want to simulate:\n");
    int N;
    scanf("%d",&N);

    //input detection
    if(N<=0){
        printf("\nERROR! CHECK YOUR INPUT!");
        return 0;
    }
    
    

    //initialize initial population
    math_func func;
    indiv Fath(0,func);
    indiv Chld(1,func);
    
    // for(int i=0;i<100;i++){
    //     printf("%llf\n",Fath.show(i));
    // }

    
    for(int i=1;i<N;i++){
        double fit=0;
        double best=itod(Fath.show(0));
        
        for(int j=0;j<100;j++){
            fit+=(func.result(Fath.show(j))/100);
            //printf("#%llf   %llf\n",fit,Fath.show(j));
            if(func.result(Fath.show(j))<func.result(dtoi(best))) best=itod(Fath.show(j));
        }
        
        // fit=(fit+func.result(dtoi(best)))/2;
        
        for(int j=0;j<100;j++){
            //printf("tag111\n");
            if (func.result(Fath.show(j))<fit){
                Chld.set(Fath.show(j),j);
                printf("retain-                  Courrent data is : ");
                showbits_rt(Chld.show(j));
            }
            else if((rand64(i+j)%3)&&(j!=99)){
                int64 retA,retB;
                //showbits(Fath.show(j));
                func.crossover(Fath.show(j),Fath.show(j+1),&retA,&retB);
                //printf("pass1\n");
                Chld.set(retA,j);
                Chld.set(retB,++j);
                printf("crossover                Courrent data is : ");
                showbits_rt(retA);
                // printf("stop\n");
                printf("crossover                Courrent data is : ");
                showbits_rt(retB);
            }
            else {
                
                Chld.set(func.mutation(Fath.show(j)),j);
                printf("mutation                 Courrent data is : ");
                showbits_rt(Chld.show(j));
                
            }
        }
        printf("The best of individual of generation %3d is ",i);
        
        showbits(dtoi(best));
        //printf("-----------%llf-----------",fit);
        Fath=Chld;
    }
    double best=itod(Fath.show(0));
    double fit=0;
        for(int j=0;j<100;j++){
        fit+= func.result(j)/100;
        if(func.result(Fath.show(j))<func.result(dtoi(best)))best=itod(Fath.show(j));
    }
    cout<<"The best of individual of generation  "<<N<<" is ";
    showbits(dtoi(best));
    printf("best:%llf\n",best);
    cout<<"best result is "<<func.result(dtoi(best));
}
