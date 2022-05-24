#include<bits/stdc++.h>
using namespace std;
#define n 4
#define edges 6
#define inf 200
int graph[20][20];
int connectedSet[20];
int z=0;
priority_queue <int , vector<int>, greater<int> > pq;

bool isSafe(int node1, int node2){
    bool flag1=false, flag2= false;
    for(int i=0; i<n; i++){
        if(connectedSet[i]==node1)
            flag1=true;
        if(connectedSet[i]==node2)
            flag2=true;
    }
    if(flag1 && flag2){
        //cout<< node1<<"\t"<<node2<<"\tcycle"<<endl;
        return false;
    }

    else{
        if(!flag1){
            connectedSet[z]=node1;
            z++;
        }
        if(!flag2){
            connectedSet[z]=node2;
            z++;
        }
        return true;
    }
}

void kruskal(){
int i=0, j=0;
bool flag;
    for(int k=0;k<edges;k++){
        flag =false;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(graph[i][j]==pq.top()){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(isSafe(i, j)){
            cout<<i<<"\t"<<j<<"\t"<<graph[i][j]<<endl;
            graph[i][j]=inf;
            }
    pq.pop();

    }
}

int main(){
    int m1, m2, w;

    for(int i=0;i<n;i++)
        for(int j =0;j<n;j++){
            graph[i][j]=inf;
        }
    memset(connectedSet, -1, sizeof connectedSet);
    for(int i=0;i<edges;i++){
        cin>>m1>>m2>>w;
        graph[m1][m2]=w;
        pq.push(w);
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    kruskal();
}

/**
0 1 2
0 2 4
0 3 3
1 2 8
1 3 1
2 3 6
*/

