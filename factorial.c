#include<stdio.h>

int fact(int n){
    
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
}

