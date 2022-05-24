/////////////////////////////////////////////////
/////////////////17.02.04.106//abir//////////////
/////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

int disk[100];
int beginRod[100];
int helpRod[100];
int endRod[100];
int movement=0;
int top=-1;

void push(int n,int b,int h,int e)
{
    top++;
    disk[top]=n;
    beginRod[top]=b;
    helpRod[top]=h;
    endRod[top]=e;

}
int* pop()
{
   static int arr[4];
    arr[0]=disk[top];
    arr[1]=beginRod[top];
    arr[2]=helpRod[top];
    arr[3]=endRod[top];
    top--;
    return arr;
}
void hanoi(int disks,int bRod,int hRod,int eRod)
{
    int n,b,h,e;
    int* ar ;

    push(disks,bRod,hRod,eRod);

    while(top!=-1)
    {
        ar = pop();
        n=ar[0],b=ar[1],h=ar[2],e=ar[3];

        if(n==1){
            cout<<"move disk"<<" from "<<b<<" to "<<e<<endl;
            movement++;
        }

        else
            {
            push(n-1,h,b,e);
            push(1,b,h,e);
            push(n-1,b,e,h);
            }

   }
}
int main (void){
    int n;
    cin>>n;
    hanoi(n,1,2,3);
    cout<<"Movements: "<<movement<<endl;
    return 0;
}
