#include<stdio.h>
int arr[8]={0,10,80,30,90,40,50,70};

void quick(int first,int last){
    int i, j,temp;
    if(first<last){
        j=last-1;
        i=first;
        while(arr[last]>arr[j])j--;
        while(arr[last]<arr[i])i++;
        while(j>i){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            while(arr[last]>=arr[j])j--;
            while(arr[last]<=arr[i])i++;
        }
        temp=arr[last];
        arr[last]=arr[i];
        arr[i]=temp;
        quick(first,i-1);
        quick(i+1,last);

    }
}
int main()
{
    int i;
    quick(1,7);
    for(i=1; i<=7; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

