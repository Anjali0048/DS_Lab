#include<stdio.h>

// TOH -> tower of hanoi

void TOH(int n, char from_rod, char to_rod, char aux_rod){

    if(n==1){
        printf("disc 1 is moved from %c rod to %c rod\n", from_rod, to_rod);
        return;
    }
    
    else{
        TOH(n-1, from_rod, aux_rod, to_rod);
        printf("disc %d is moved from %c rod to %c rod\n",n, from_rod, to_rod);
        TOH(n-1, aux_rod, to_rod, from_rod);
    }
}

int main(){
    char A,B,C;
    
    TOH(3,'A','C','B');  
    
}