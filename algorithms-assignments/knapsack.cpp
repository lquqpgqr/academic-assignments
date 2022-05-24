#include<bits/stdc++.h>
using namespace std;

int table[50][50];
int profit[50], weight[50],items[50],pickup[50];
int bag,product;
int check,money,frow,fcol;


void knapsack(){
    for(int row=0;row<=product;row++)
    table[row][0]=0;
    for(int col=0;col<=bag;col++)
    table[0][col]=0;


    for(int row=1;row<=product;row++)
        for(int col=1;col<=bag;col++){
            check=col-weight[row];
            if(check>=0)
                table[row][col]=max(table[row-1][col],
                (table[row-1][col-weight[row]]+profit[row]));
            else
                table[row][col]=table[row-1][col];
            }
    for(int row=0;row<=product;row++){
        for(int col=0;col<=bag;col++){
            cout<<table[row][col]<<"\t";
        }
            cout<<endl;
    }

    money=table[product][bag];
    cout<<"total: "<<money<<endl;
    frow=product;
    fcol=bag;
    while(frow>0 && fcol>0){
        if(table[frow][fcol] != table[frow-1][fcol]){
            pickup[frow]=1;
            fcol=fcol-weight[frow];
            frow=frow-1;
        }else{
            pickup[frow]=0;
            frow=frow-1;
        }
    }
    cout<<"products chosen:"<<endl;
    for(int i=1;i<=product;i++)
        cout<<pickup[i]<<" ";
    cout<<endl;

}

int main(){
    cout<<"bag size: ";
    cin>>bag;
    cout<<"how many products: ";
    cin>>product;
    cout<<"profits: ";
    for(int i=1;i<=product;i++)
        cin>>profit[i];
    cout<<"weight: ";
    for(int i=1;i<=product;i++)
        cin>>weight[i];
    knapsack();

    return 0;

}
