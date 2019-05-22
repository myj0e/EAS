#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>

typedef unsigned long long int64_t;
using namespace std;


void showbits(int64_t bit64){
    int64_t temp=1;
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


int main(){
    int64_t x[2];
    int pos=15;
    
    FILE* fp=fopen("random","r");
    if(fp==NULL){
        printf("Open Error\n");
        return 0;
    }
    //printf("%d\n",sizeof(fp));
    showbits(97996598797);
    while(pos>=0){
        printf("1-- %lld ticks\n",GetTickCount());
        fseek(fp,pos,SEEK_SET);
        printf("2-- %lld ticks\n",GetTickCount());
        //scanf("%d",&pos);
        fread(x,8,2,fp);
        showbits(x[0]*x[1]);
        Sleep(10);
    }
    fclose(fp);
}
