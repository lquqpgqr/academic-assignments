#include<stdio.h>
int main(){
    int i, j, m=5,k=5,temp,temp2;
    int arr[10]={3,2,6,4,7,9,1,11,7,5};
    for(i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    while(m!=0){
        int t=0;
        for(i=0;i<5;i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                t=i;
            }
        }m=t;
    }
/*
    while(k!=0){
         int u=0;
        for(i=5;i<10;i++){
            if(arr[i]<arr[i+1]){
                temp2=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                u=i;
            }
        }k=u;
    }
*/
    for(i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
