/////////////////////////////////////////////////
/////////////////17.02.04.106//abir//////////////
/////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
int movement=0;
int hanoi(int n, char beginRod, char helpRod, char endRod){
    if(n==1){
            cout<<"move disk 1 from "<<beginRod<<" to "<<endRod<<endl;
            movement++;
    }
    else{
        hanoi(n-1,beginRod,endRod,helpRod);
        cout<<"move disk "<<n<<" from "<<beginRod<<" to "<<endRod<<endl;
        movement++;
        hanoi(n-1,helpRod,beginRod,endRod);
    }
}
int main(){
    int n;
    cin>>n;
    hanoi(n,'i','j','k');
    cout<<"Movements: "<<movement<<endl;
    return 0;
}
