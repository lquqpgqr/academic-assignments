#include<bits/stdc++.h>
using namespace std;

int graph[50][50];
int piGraph[50][50];
int nodes,edges;
#define INT_MAX 100

bool floyd_warshall(){
    for (int k = 0; k < nodes; k++)
        for (int i = 0; i < nodes; i++)
            for (int j = 0; j < nodes; j++){
                if (graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    piGraph[i][j]=k;
                }
                if(graph[i][j]==0||graph[i][j]==INT_MAX)
                    piGraph[i][j]=INT_MAX;

            }
    for (int i = 0; i < nodes; i++)
        if (graph[i][i] < 0)
            return true;
    return false;


}

void print_cost(){
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(graph[i][j]==INT_MAX) cout<<"I ";
            else
            cout<< graph [i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(piGraph[i][j]==INT_MAX) cout<<"I ";
            else
            cout<< piGraph [i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){

    cin>>nodes>>edges;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<edges;i++){
        int u1, v1, w;
        cin>>u1>>v1>>w;
        graph[u1][v1]=w;
    }
    cout<<endl;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(graph[i][j]==INT_MAX) cout<<"I ";
            else
            cout<< graph [i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    if(floyd_warshall())
        cout<<"Negative cycle"<<endl;
    else
        print_cost();

    return 0;
}

