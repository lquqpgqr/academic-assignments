#include<bits/stdc++.h>
using namespace std;
typedef struct node node;
struct node{
    int data;
    node *link;
};
//////////////////////////////////////////////////////
void insertFirst(node *dummy,int data){
    node *newNode= (node *)malloc(sizeof(node));
    newNode-> data = data;
    newNode->link = dummy->link;
    dummy->link = newNode;
}
//////////////////////////////////////////////////////
void insertLast(node *dummy,int data){
    node *newNode= (node *)malloc(sizeof(node));
    node *p =dummy;
    while(p->link!=NULL){
        p=p->link;
    }
    newNode-> data = data;
    newNode->link = p->link;
    p->link = newNode;
}
//////////////////////////////////////////////////////
void insertBefore(node *dummy,int checker,int data){
    node *newNode= (node *)malloc(sizeof(node));
    node *pred=dummy;
    node *p=pred->link;
    while(p!=NULL){
        if(checker==p->data){
            newNode->link=pred->link;
            pred->link=newNode;
            newNode->data=data;
            break;
        }
        else{
            pred=p;
            p=p->link;
        }
    }
}
//////////////////////////////////////////////////////
void deleteFont(node *dummy){
    node *p;
    if(dummy->link!=NULL){
        p=dummy->link;
        dummy->link=p->link;
    }
}
//////////////////////////////////////////////////////
void deleteLast(node *dummy){
    node *pred, *p;
    pred=dummy;
    p=pred->link;
    if(dummy->link!=NULL){
        while(p->link!=NULL){
            pred=p;
            p=p->link;
        }
        pred->link=NULL;
    }
}
//////////////////////////////////////////////////////
void deletespf(node* dummy,int data){
    node *pred=dummy;
    node *p=pred->link;
    while(p!=NULL){
        if(data==p->data){
            pred->link=p->link;
            break;
        }
        else{
            pred=p;
            p=p->link;
        }
    }
}
//////////////////////////////////////////////////////
void print(node *dummy){
    node* pred = dummy->link;
    cout <<"list is: ";
    while(pred != NULL){
            cout << pred->data <<" ";
            pred=pred->link;
    }
    cout <<endl;
}
//////////////////////////////////////////////////////
int main(){
    int i,n,num,choise,checker;
    node *dummy;
    dummy=(node *) malloc(sizeof(node));
    dummy->link=NULL;
    do{
        cout <<"Menu:\n1.insert at first.\t";
        cout <<"2.insert at last.\t";
        cout<<"3.insert before."<<endl;
        cout <<"4.delete from first.\t";
        cout <<"5.delete from last.\t";
        cout <<"6.delete specific."<<endl;
        cout <<"7.exit"<<endl;
        cin >>choise;
        if (choise==1){
                cout <<"number: ";
                cin >>num;
            insertFirst(dummy,num);
            print(dummy);
        }else if (choise==2){
                cout <<"number: ";
                cin >>num;
            insertLast(dummy,num);
            print(dummy);
        }
        else if (choise==3){
                cout <<"before which number?: ";
                cin >>checker;
                cout <<"number: ";
                cin >>num;
                insertBefore(dummy,checker,num);
                print(dummy);
        }else if (choise==4){
            deleteFont(dummy);
            print(dummy);
        }
        else if (choise==5){
            deleteLast(dummy);
            print(dummy);
        }
        else if (choise==6){
                cout <<"delete which number?: ";
                cin >>num;
                deletespf(dummy,num);
                print(dummy);
        }

    }while(choise!=7);
    return 0;
}
