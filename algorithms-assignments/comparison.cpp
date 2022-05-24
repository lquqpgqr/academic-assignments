#include<bits/stdc++.h>
using namespace std;
int test[1000001];
int insertion(int arr[],int n){
    clock_t st, en;
    st = clock();
    int t,i,j;
    arr[0]=pow(2,32);
    for(j=2;j<=n;j++){
        t=arr[j];
        i=j-1;
        while(t<arr[i]){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=t;
    }
    en = clock();
    double time_taken = double(en - st) / double(CLOCKS_PER_SEC);
    cout << "Time taken by insertion is : " << time_taken;
    cout << " sec " << endl;

}
void mergeing(int arr[],int p,int q,int r){
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
void sorting(int arr[],int p,int r){
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        sorting(arr,p,q);
        sorting(arr,q+1,r);
        mergeing(arr,p,q,r);
    }
}
int mergesort(int arr[],int n){
    clock_t st, en;
    st = clock();
    sorting(arr,1,n);
    en = clock();
    double time_taken = double(en - st) / double(CLOCKS_PER_SEC);
    cout << "Time taken by mergesort is : " << time_taken << setprecision(5);
    cout << " sec " << endl;
}

int main(){
    srand((unsigned)time(0));
    for(int i=10000;i<1000000;i+=100000){
        for(int j=0;j<i;j++){
            test[j]=rand();
        }
        insertion(test,i);
        mergesort(test,i);
    }
    return 0;
}
