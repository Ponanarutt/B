#include<stdio.h>
#include<stdlib.h>

int globaldata ;
int globaldata1 = 1 ;
int globaldata2 = 1 ;

void SH(int c){

    while(1){
    int s = c ;
    printf("stack address : %p\n" , c , (void*)&s);

    int *h = (int*)malloc(4);
    *h = c ;
    printf("heap address : %p\n" , c ,(void*)h);

    if(c > 5){
        break ;
    } 
    c++ ;
    }
}

void overflow(int c , char n){
    SH(c);
    if(n=='y'){
        overflow(c+5,n)
    }
}

int main(){

    printf("gloval address: %p\n", (void*)&globaldata);
    printf("gloval address: %p\n", (void*)&globaldata1);
    printf("gloval address: %p\n", (void*)&globaldata2);

    char n ;

    SH(1);
    scanf("%c" , &n);
    if(n == 'y'){
        overflow(6,n);}
    return 0 ;
}
