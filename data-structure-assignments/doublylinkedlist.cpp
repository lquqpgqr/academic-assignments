//////////////////////////////////////////////////////
///////doubly linked list///abir///17.02.04.106///////
//////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
typedef struct node node;
struct node{
    int data;
    node *flink;
    node *blink;
};
//////////////////////////////////////////////////////
void insertFirst(node *dummyHead,int data){
    node *newNode= (node *)malloc(sizeof(node));
    node *p=dummyHead->blink;

    newNode-> data = data;
    newNode->flink=dummyHead;
    newNode->blink=p;
    p->flink=newNode;
    dummyHead->blink=newNode;

}
//////////////////////////////////////////////////////
void insertLast(node *dummyTail,int data){
    node *newNode= (node *)malloc(sizeof(node));
    node *p =dummyTail->flink;

    newNode-> data = data;
    newNode->flink = p;
    newNode->blink = dummyTail;
    p->blink = newNode;
    dummyTail->flink=newNode;
}
//////////////////////////////////////////////////////
void insertBefore(node *dummyHead,node *dummyTail, int checker,int data){
    node *newNode= (node *)malloc(sizeof(node));
    node *q=dummyHead->blink;
    node *p;
    while(q!=dummyTail){
        if(checker==q->data){
            p=q->flink;
            newNode->flink=p;
            newNode->blink=q;
            p->blink=newNode;
            q->flink=newNode;
            newNode->data=data;
            break;
        }
        else{
            q=q->blink;
        }
    }
}
//////////////////////////////////////////////////////
void deleteFont(node *dummyHead, node *dummyTail){
    node *p;
    if(dummyHead->blink!=dummyTail){
        p=dummyHead->blink;
        p=p->blink;
        p->flink=dummyHead;
        dummyHead->blink=p;
    }
}
//////////////////////////////////////////////////////
void deleteLast(node* dummyHead, node *dummyTail){
    node *p;
    if(dummyTail->flink!=dummyHead){
        p=dummyTail->flink;
        p=p->flink;
        p->blink=dummyTail;
        dummyTail->flink=p;
    }
}
//////////////////////////////////////////////////////
void deletespf(node *dummyHead,node *dummyTail,int data){
    node *q=dummyHead->blink;
    node *p;
    while(q!=dummyTail){
        if(data==q->data){
            p=q->flink;
            q=q->blink;
            p->blink=q;
            q->flink=p;
            break;
        }
        else{
            q=q->blink;
        }
    }
}
//////////////////////////////////////////////////////
void print(node *dummyHead,node *dummyTail){
    node* p = dummyHead->blink;
    node *q= dummyTail;
    cout <<"list is: ";
    while(p != q){
            cout << p->data <<" ";
            p=p->blink;
    }
    cout <<endl;
}
//////////////////////////////////////////////////////
void printReverse(node *dummyHead,node *dummyTail){
    node* p = dummyHead;
    node *q= dummyTail->flink;
    cout <<"list in reverse is: ";
    while(p != q){
            cout << q->data <<" ";
            q=q->flink;
    }
    cout <<endl;
}
//////////////////////////////////////////////////////
int main(){
    int i,n,num,choise,checker;
    node *dummyHead;
    node *dummyTail;
    dummyHead=(node *) malloc(sizeof(node));
    dummyTail=(node *) malloc(sizeof(node));
    dummyHead->flink=NULL;
    dummyHead->blink=dummyTail;
    dummyTail->flink=dummyHead;
    dummyTail->blink=NULL;

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
            insertFirst(dummyHead,num);
            print(dummyHead,dummyTail);
            printReverse(dummyHead,dummyTail);
        }else if (choise==2){
                cout <<"number: ";
                cin >>num;
            insertLast(dummyTail,num);
            print(dummyHead,dummyTail);
            printReverse(dummyHead,dummyTail);
        }
        else if (choise==3){
                cout <<"before which number?: ";
                cin >>checker;
                cout <<"number: ";
                cin >>num;
                insertBefore(dummyHead,dummyTail,checker,num);
                print(dummyHead,dummyTail);
                printReverse(dummyHead,dummyTail);
        }else if (choise==4){
            deleteFont(dummyHead,dummyTail);
            print(dummyHead,dummyTail);
            printReverse(dummyHead,dummyTail);
        }
        else if (choise==5){
            deleteLast(dummyHead,dummyTail);
            print(dummyHead,dummyTail);
            printReverse(dummyHead,dummyTail);
        }
        else if (choise==6){
                cout <<"delete which number?: ";
                cin >>num;
                deletespf(dummyHead,dummyTail,num);
                print(dummyHead,dummyTail);
                printReverse(dummyHead,dummyTail);
        }

    }while(choise!=7);
    return 0;
}
