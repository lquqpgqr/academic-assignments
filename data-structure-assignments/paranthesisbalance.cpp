#include<bits/stdc++.h>
using namespace std;

char arr[50];
int top=-1;
bool flag;

void push(char ch){
    if(top<50){
        top++;
        arr[top]=ch;
    }
}
void pop(){
    char ch;
    if(top!=-1){
        //arr[top];
        top--;
    }
}
char topp(){
    char ch;
    if(top!=-1){
        ch =arr[top];
        return ch;
    }
}

bool pairing(char opening, char closing){

    if(opening == '('&& closing == ')') return true;
    else if(opening == '{'&& closing == '}') return true;
    else if(opening == '['&& closing == ']') return true;
    else return false;
}
bool balance(char* arr){
    int n= strlen(arr);
    for(int i=0; i<n;i++){
        if(arr[i]=='('||arr[i]=='{'||arr[i]=='[')
            push(arr[i]);
        else if(arr[i]==')'||arr[i]=='}'||arr[i]==']'){
            if(top==-1 || !pairing(topp(),arr[i])){
                return false;
            }
            else pop();
        }
    }if(top==-1) return true;
    else return false;

}
int main(){
    int i=0;
    char ar[50];
    gets(ar);
    cout<<strlen(ar)<<endl;


    if(balance(ar)) cout<< "balanced"<<endl;
    else cout<< "not balanced"<<endl;
    return 0;
}
