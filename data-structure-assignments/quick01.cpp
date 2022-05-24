#include<stdio.h>
int arr[100];
void quick(int first,int last)
{
    int i,j,temp;
    if(first<last)
    {
        i=first+1;
        j=last;
        while(arr[first]>arr[i]) i++;
        while(arr[first]<arr[j]) j--;
        while(i<j)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            while(arr[first]>=arr[i]) i++;
            while(arr[first]<=arr[j]) j--;
        }
        temp=arr[first];
        arr[first]=arr[j];
        arr[j]=temp;
        quick(first,j-1);
        quick(j+1,last);
    }
}
int main()
{
    int n,i;
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Elements:");
    for(i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    quick(1,n);
    for(i=1; i<=n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

