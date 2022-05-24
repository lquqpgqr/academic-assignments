#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int arr[1000];
void mergeing(int arr[],int p,int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(i=1; i<=n1; i++){
        L[i]=arr[p+i-1];
    }
    for(j=1; j<=n2; j++){
        R[j]=arr[q+j];
    }
    L[n1+1]=(int)pow(2,32);
    R[n2+1]=(int)pow(2,32);
    i=1;
    j=1;
    for(k=p; k<=r; k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i=i+1;
        }
        else{
            arr[k]=R[j];
            j=j+1;
        }
    }
}
void sorting(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        sorting(arr,p,q);
        sorting(arr,q+1,r);
        mergeing(arr,p,q,r);
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
    sorting(arr,1,n);
    for(i=1; i<=n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
