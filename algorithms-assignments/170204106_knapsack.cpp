#include<bits/stdc++.h>
using namespace std;
int table[50][50];
int bag,product,x;
int profits[50],weights[50];


void knapsack(){

    for(int col=0; col<=bag; col++){
        table[0][col]=0;
    }
    for(int row=0;row<=product; row++){
        table[row][0]=0;
    }



    for(int row=1; row<=product; row++){
        for(int col=1; col<=bag;col++){
            x=row-weights[row];
            if(x>=0)
                table[row][col]=max(table[row][col-1],table[x+profits[x]][col-1]);
            else table[row][col]=table[row][col-1];

        }

    }
    for(int row=0; row<=product; row++){
        for(int col=0; col<=bag;col++){
            cout<<table[row][col]<<"\t";
        }
            cout<<endl;
        }



}


int main(){

    cout<<"Bag size: ";
    cin>>bag;
    cout<<"how many products: ";
    cin>>product;
    cout<<"profits: ";
    for(int i=1;i<=product;i++)
        cin>>profits[i];
    cout<<"weights: ";
    for(int i=1;i<=product;i++)
        cin>>weights[i];

    knapsack();

}
