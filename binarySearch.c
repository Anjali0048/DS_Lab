#include<stdio.h>

int binarySearch( int arr[], int key, int s, int e){
    
    while(s <= e){
        
        int mid = s + (e-s)/2;
        
        if(arr[mid] == key){
            return mid;
        }
        
        if(arr[mid] < key){
            return binarySearch(arr, key, mid+1, e);
        }
        
        else{
            return binarySearch(arr, key, s, mid-1);
        }
    }
    return 1;      
}

int main(){
    
    int arr[8] = {1,3,5,7,9,13,26,48};
    printf("%d\n",binarySearch(arr,26,0,7));
       
}