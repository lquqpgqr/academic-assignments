#include<bits/stdc++.h>
using namespace std;

int graph[50][50];
int color[50],discover[50],finish[50],parent[50];
int nodes, edges,source,ttime=0;
int white=1,gray=2,black=3;
int font=0,rear=0,itemcount=0;
int arr[50];

void DFSvisit(int u);

void graphDFS(int nodes){
    for(int i=1;i<=nodes;i++){
        color[i]=white;
        parent[i]=-1;
    }
    for(int i=1;i<=nodes;i++){
        if(color[i]==white){
            DFSvisit(i);
        }
    }
}
void DFSvisit(int u){
    ttime=ttime+1;
    discover[u]=ttime;
    color[u]=gray;
    int v;
    for(int i=1;i<=nodes;i++){
        if(graph[u][i]==1){
            v=i;
            if(color[v]==white){
                parent[v]=u;
                DFSvisit(v);
            }
        }
    }
    color[u]=black;
    ttime=ttime+1;
    finish[u]=ttime;
}
int main(){
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++){
        int u, v;
        cin>>u>>v;
        graph[u][v]=1;
        //graph[v][u]=1;
    }
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout<< graph [i][j] << " ";
        }
        cout<<endl;
    }
    graphDFS(nodes);
    for(int i = 1; i <=nodes; i++){
		cout<<i<<" -> "<<discover[i]<<" "<<finish[i]<<endl;
	}
return 0;
}
