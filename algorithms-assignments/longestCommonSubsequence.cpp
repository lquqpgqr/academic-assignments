#include<bits/stdc++.h>
using namespace std;
int i,j,m,n,b[20][20],c[20][20];
char x[20],y[20];

void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]==1){
        print_lcs(i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==2)
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}
void longestCommonSubsequence(){
    m=strlen(x);
    n=strlen(y);
    for(i=0; i<=m; i++)
        c[i][0]=0;
    for(i=0; i<=n; i++)
        c[0][i]=0;
    ///1 for diagonal//2 for up//3 for back
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
}
int main(){
    printf("Enter 1st sequence:");
    gets(x);
    printf("Enter 2nd sequence:");
    gets(y);

    printf("\nThe Longest Common Subsequence is ");
    longestCommonSubsequence();
    print_lcs(m,n);
    return 0;
}
