#include<bits/stdc++.h>
using namespace std;

int n,arrSize=0,arrLast;
int arr[50];
int getLeftChildIndex(int parentIndex){
    return 2*parentIndex+1;
}
int getRightChildIndex(int parentIndex){
    return 2*parentIndex+2;
}
int getParentIndex(int childIndex){
    return (childIndex-1)/2;
}
bool hasLeftChild(int index){
    if(getLeftChildIndex(index)< arrSize) return true;
    else return false;
}
bool hasRightChild(int index){
    if(getRightChildIndex(index)< arrSize) return true;
    else return false;
}
bool hasParent(int index){
    if(getParentIndex(index)>=0) return true;
    else return false;
}

void heapifyUp(){
    int index =arrSize-1;
    while(hasParent(index)&&arr[getParentIndex(index)]<arr[index]){
        swap(arr[getParentIndex(index)],arr[index]);
        index=getParentIndex(index);
    }
}

void heapifyDown(){
    int index=0;
    while(hasLeftChild(index)){
        int smallerChildIndex= getLeftChildIndex(index);
        if(hasRightChild(index)&& arr[getRightChildIndex(index)]>arr[getLeftChildIndex(index)])
            smallerChildIndex=getRightChildIndex(index);
        if(arr[index]>arr[smallerChildIndex]) break;
        else {
            swap(arr[index],arr[smallerChildIndex]);
        }
        index=smallerChildIndex;
    }
}


void add(int item){
    arr[arrSize]=item;
    arrSize++;
    heapifyUp();
}
void poll(){
    int item=arr[0];
    arr[0]=arr[arrSize-1];
    arrSize--;
    heapifyDown();
    arr[arrLast]=item;
    arrLast--;
    //return item;
}

int main(){
    int i,data;

    cout<<"number of elements: ";
    cin>>n;
    arrLast=n-1;
    cout<<"elements: ";
    for(i=0;i<n;i++){
        cin>>data;
        add(data);
    }
    while(arrSize>0) poll();
        //cout<<poll()<<" ";
    for(i=0;i<n;i++){
        cout<<arr[i];
    }

}
