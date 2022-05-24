#include<bits/stdc++.h>
using namespace std;
#define TRUE 1
#define FALSE 0
int inc[50],w[50],sum,n;

int promising(int i,int wt,int total){
	return(((wt+total)>=sum)&&((wt==sum)||(wt+w[i+1]<=sum)));
}

void sumset(int i,int wt,int total){
	int j;
 	if(promising(i,wt,total)){
  		if(wt==sum){
   			cout<<endl;
   			for(j=0;j<=i;j++)
    			if(inc[j]) cout<<" "<<w[j];
   			cout<<endl;
  		}
		else{
   			inc[i+1]=TRUE;
   			sumset(i+1,wt+w[i+1],total-w[i+1]);
   			inc[i+1]=FALSE;
   			sumset(i+1,wt,total-w[i+1]);
  		}
 	}
}

int main(){
	int i,j,n,temp,total=0;
 	cout<<"elements no. in set:";
 	cin>>n;
    cout<<"\nelements:";
	for(i=0;i<n;i++){
  		cin>>w[i];
  		total+=w[i];
 	}
    cout<<"\nsum:";
    cin>>sum;
    sort(w,w+n);
 	if((total<sum))
        cout<<"\nno subsets:";
	else{
  		for(i=0;i<n;i++)
   			inc[i]=0;
  		cout<<"\nsolution:\n";
  		sumset(-1,0,total);
 	}
 	return 0;
}




