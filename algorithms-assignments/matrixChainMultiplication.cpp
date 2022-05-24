#include<bits/stdc++.h>
using namespace std;
#define n 5
#define inf 9999
int s[n][n], m[n][n];
void print_optimal(int i,int j){
    if (i == j)
        cout<<"a"<<i;
    else{
        cout<<"("
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j] + 1, j);
        cout<<")";
    }
}
int main (void){
    int p[]= {5,4,6,2,7};
    memset(m,0,sizeof m);
    memset(s,0,sizeof s);
    int i,j,minimum,q,d,k;
    for(d=1; d<n-1; d++){
        for(i=1; i<n-d; i++){
            j=i+d;
            minimum=inf;
            for(k=i ; k<=j-1; k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<minimum){
                    minimum=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=minimum;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            cout<<m[i][j]<<"\t";
        cout<<endl;
    }
print_optimal(1,4);
    return 0;
}

