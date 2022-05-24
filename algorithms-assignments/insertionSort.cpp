#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i,j;
    int arr[50];
    cout<<"size: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
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
    for(i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

}

