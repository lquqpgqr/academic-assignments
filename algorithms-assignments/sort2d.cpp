#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int *a, int *b){
    // sorting on basis of 2nd column
    return a[1] < b[1];
}

void sorting(int **arr,int n){
    //calling in built sort
    sort(arr, arr + n, compare);
    // printing after sorting 
    cout<<"---------After Sorting---------"<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
}

int main(){
    int **arr, i, n;
    cout<<"Enter the size of array  : ";
    cin>>n;
    //array of size arr[n][2]; 
    arr = new int*[n];
    for(i = 0; i < n; i++){
        arr[i] = new int[2];
    }
    
    for(int i = 0; i < n; i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    
    sorting(arr, n);
    return 0;
}
