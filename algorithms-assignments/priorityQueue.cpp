#include<bits/stdc++.h>
using namespace std;
typedef struct node node;
struct node{
    int data;
    node* link;
};

void deleteFont(node *dummy){
    node *p;
    if(dummy->link!=NULL){
        p=dummy->link;
        dummy->link=p->link;
    }
}
void insertsort(node *dummy, int data){
    node *newNode = (node *)malloc(sizeof(node));
    node *p=dummy;
    node *after=p->link;
        while(after!=NULL){
                if(data<after->data){
                    p=after;
                    after=after->link;
                }
                else break;
        }
    newNode->data=data;
    newNode->link=p->link;
    p->link=newNode;

}
void print(node *dummy){
    node *p;
    p=dummy->link;
    cout<<"elements: ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->link;
    }
    cout<<endl;

}
int main(){
    int num,choise=1;
    node *dummy= (node *)malloc(sizeof(node));
    dummy->link=NULL;
    while(choise!=3){
        cout<<"choise:1.input\t2.pop\t3.exit"<<endl;
        cin>>choise;
        if(choise==1){
            cout<< "Insert data: ";
        cin>> num;
        insertsort(dummy,num);
        print(dummy);
        }
        if(choise==2){
            deleteFont(dummy);
        print(dummy);
        }



    }

return 0;
}
