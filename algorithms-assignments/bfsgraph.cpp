#include<bits/stdc++.h>
using namespace std;

int graph[50][50];
int color[50],dist[50],parent[50];
int nodes, edges,source;
int white=1,gray=2,black=3;

int font=0,rear=0,itemcount=0;
int arr[50];

void push(int item){
    if(itemcount!=50){
        arr[font]=item;
        itemcount++;
        if(font>50) font =0;
        else font++;
    }
}
int pop(){
    int x=0;
    if(itemcount>0){
        x=arr[rear];
        itemcount--;
        if(rear>50) rear=0;
        else rear ++;
    return x;
   }
}
void graphBFS(int graph[][50],int source){
    for(int i=1; i<=nodes;i++){
        if(i!=source){
            color[i]=white;
            dist[i]= INT_MAX;
            parent[i]=-1;
        }
    }
    color[source]=gray;
    dist[source]=0;
    parent[source]=-1;
    push(source);
    int u,v;
    while(itemcount!=0){
        u=pop();
        cout<<u<<" ";
        for(int i=1; i<=nodes; i++){
            if(graph[u][i]==1){
                v=i;
                if(color[v]==white){
                    color[v]=gray;
                    dist[v]=dist[u]+1;
                    parent[v]=u;
                    push(v);
                }
            }
        }color[u]=black;
    }
    cout<<endl;
    cout<<endl;
    for(int i=1;i<=nodes;i++){
        cout<<source<<" -> "<<i<<" = "<<dist[i]<<endl;
    }

}

int main(){
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++){
        int u, v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    cin>>source;
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout<< graph [i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    graphBFS(graph, source);
    return 0;
}
