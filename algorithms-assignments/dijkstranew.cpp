#include<bits/stdc++.h>
using namespace std;

int graph[50][50];
int dist[50],parent[50];
bool visited[50];
int source,nodes,edges;

int findMinVertex(int* dist, bool* visited, int n){

    int minVertex =-1;
    for(int i=0; i<n;i++){
        if(!visited[i]&&( minVertex== -1 || dist[i]< dist[minVertex]))
            minVertex=i;
    }
    return minVertex;
}

void initialize_single_source(int source){
    for(int i=0; i<nodes;i++){
            dist[i]= INT_MAX;
            visited[i]=false;
    }
    dist[source]=0;
}


void dijkstra(int source){
    initialize_single_source(source);
    for(int i=0;i<nodes-1;i++){

        int minVertex = findMinVertex(dist,visited,nodes);
        visited[minVertex]=true;
        for(int j=0;j<nodes;j++){
            if(graph[minVertex][j] !=0 && !visited[j]){
                int dista= dist[minVertex]+graph[minVertex][j];
                if(dista<dist[j]){
                    dist[j]= dista;
                }
            }


        }
    }
    for(int i=0;i<nodes; i++){
        cout<<i<<" "<< dist[i]<<endl;
    }

}




int main(){

    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int u1, v1, w;
        cin>>u1>>v1>>w;
        graph[u1][v1]=w;

    }
    cin>>source;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<< graph [i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    dijkstra(source);
    return 0;
}
