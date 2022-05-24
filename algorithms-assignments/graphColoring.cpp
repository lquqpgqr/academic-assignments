
#include<bits/stdc++.h>
using namespace std;

int graph[50][50];
int color[50]={0},impossible[50];
int nodes, edges,source,m=3,alpha=96;

bool available(int k,int c){
    for(int i= 1;i<=nodes;i++){
        if(graph[k][i]==1&& c==color[i]){
            ///impossible[k]=c;
            return false;
        }
    }
    return true;
}
void graphColoring(int k){

    for(int c=1;c<=m;c++){
        if(available(k,c)){
            color[k]=c;
            if((k+1)<=nodes)
                graphColoring(k+1);
            else break;
        }
    }
}

int main(){
    cin>>nodes>>edges;
    char x,y,z;

    for(int i=1;i<=edges;i++){
        int u, v;
        cin>>x>>y;
        u=x-alpha;
        v=y-alpha;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    cin>>z;
    source=z-alpha;
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout<< graph [i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    graphColoring(source);
    for(int i=1;i<=nodes;i++)
        cout<<"node: "<<char(i+alpha)<<" color: "<<color[i]<<endl;
    //for(int i=1;i<=nodes;i++)
        //cout<<"node: "<<char(i+alpha)<<" imp: "<<impossible[i]<<endl;
    //return 0;
}
/**
4 5
a b
b c
c d
d a
b d
a
4 5
a b
b c
c d
d a
a c
a
*/
