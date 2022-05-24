#include<bits/stdc++.h>
using namespace std;
#define inf 999
#define inf2 200
#define n 5
int primaryGraph[50][50];
int z=0;
int secondaryGraph[5][50][50];
int cost[5]={0};
priority_queue< int,vector<int>, greater<int> > pq;



int minimumReturn(int dorkari[n]){
    int x;
    for(int i=0;i<n;i++)
        pq.push(dorkari[i]);
    if(!pq.empty()){
        if(pq.top()>inf2){
                while (!pq.empty())
                    pq.pop();
                return 0;
        }
        else {
                x=pq.top();
                while (!pq.empty())
                    pq.pop();
        }return x;
    }
        else {
            while (!pq.empty())
                pq.pop();
            return 0;
        }
}


void leastCost(int x){
    int minList[n],dorkariArray[10];
    int tempMin;
    cout<<endl;
///row
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            minList[k]=secondaryGraph[x][i][k];
        }
        tempMin=minimumReturn(minList);
        //dorkariArray[z]=tempDorkari;
        //z++;
        for(int j=0;j<n;j++){
            secondaryGraph[x][i][j]=secondaryGraph[x][i][j]-tempMin;
        }
    }
///column
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            minList[k]=secondaryGraph[x][k][i];
        }
        tempMin=minimumReturn(minList);
        //dorkariArray[z]=tempDorkari;
        //z++;
        for(int j=0;j<n;j++){
            secondaryGraph[x][j][i]=secondaryGraph[x][j][i]-tempMin;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(secondaryGraph[x][i][j]>inf2)
                    cout<<"i\t";
                else
                    cout<<secondaryGraph[x][i][j]<<"\t";
        }
            cout<<endl;
    }

    //for(int i=0;i<10;i++){
    //    cost[x]=cost[x]+dorkariArray[i];
    //}
    //cout<<cost[x]<<endl;


}

void branchAndBound(){

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==0){
                    secondaryGraph[0][i][j]=primaryGraph[i][j];
                }else{
                    secondaryGraph[k][i][j]=secondaryGraph[0][i][j];
                }
            }
        }
        if(k!=0){
            for(int i=0;i<n;i++)
                    secondaryGraph[k][0][i]=inf;
            for(int i=0;i<n;i++)
                secondaryGraph[k][i][k]=inf;
            secondaryGraph[k][k][0]=inf;

        }
        cout<<endl;
    cout<<k<<endl;
        leastCost(k);
    }
}



int main(){
    int w;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cin>>w;
            primaryGraph[i][j]=w;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(primaryGraph[i][j]>inf2)
                    cout<<"i\t";
                else
                    cout<<primaryGraph[i][j]<<"\t";
        }
            cout<<endl;
    }
    branchAndBound();
return 0;
}
/**
999 20 30 10 11
15 999 16 4 2
3 5 999 2 4
19 6 18 999 3
16 4 7 16 999
*/


