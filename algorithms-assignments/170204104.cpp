#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int parent[100];

int find_set(int x)
{
    if(parent[x]==x)
        return x;
    else
        return find_set(parent[x]);
}

int unite(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fx] = fy;
    return 0;
}


int main()
{
    int tnodes,tedges,node1,node2,weight;
    ifstream input("kruskalinput.txt");
    input>>tnodes>>tedges;

    for(int i=1;i<=tnodes;i++)
    {
        parent[i]=i;
    }

    vector < pair<int, pair<int,int> > > edges;  //(1,(2 7))  (weight,(n1,n2))
    for(int i=1;i<=tedges;i++)
    {
        input>>node1>>node2>>weight;
        edges.push_back(make_pair(weight,make_pair(node1,node2)));
    }
    sort(edges.begin(),edges.end());

    int mst_edges=0,edge_count=0,mst_weight=0;

    while(edge_count<tedges)   //
    {
        node1=edges[edge_count].second.first;
        node2=edges[edge_count].second.second;
        weight=edges[edge_count].first;

        if(find_set(node1)!=find_set(node2))
        {
            mst_weight=mst_weight + weight;
            cout<<node1<<"->"<<node2<<" -"<<weight<<endl;
            unite(node1,node2);
            mst_edges++;
        }

        else  if(find_set(node1)==find_set(node2))
        {

            cout<<endl;
            cout<<"!!!Cycle found!!!"<<endl;
            cout<<"Edges those create cycle"<<endl;

            cout<<node1<<"->"<<node2<<endl;
            unite(node1,node2);

        }
        edge_count++;
    }



    cout<<endl;
    cout<<"Minimum cost: "<<mst_weight;
    return 0;
}

