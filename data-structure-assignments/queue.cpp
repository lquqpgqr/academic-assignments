#include<stdio.h>
int n;
int font=0,rear=0,itemcount=0;
int arr[50];

void push(int item){
    if(itemcount!=n){
        arr[font]=item;
        itemcount++;
        if(font>n) font =0;
        else font++;
        printf("font: %d\n",font);
    }else {
        printf("queue full\n");
        printf("font: %d\n",font);
    }
}
int pop(){
    int x=0;
    if(itemcount>0){
        x=arr[rear];
        itemcount--;
        if(rear>n) rear=0;
        else rear ++;
        printf("rear: %d\n",rear);
    return x;
   }
}


int main(){
     printf("Enter queue size 1~50:");
     scanf("%d",&n);
     int choise,number,popped;
     char ch;
     bool flag=true;
     do{
        printf("1.push\t2.pop: ");
        scanf("%d",&choise);
        if(choise==1){
            printf("number: ");
            scanf("%d",&number);
            push(number);
        }else if(choise==2){
            if(itemcount!=0){
                popped=pop();
                printf("%d\n",popped);
            }else {
                printf("Queue is empty.\n");
                printf("rear:%d\n",rear);
            }

        }
        printf("again?[enter/n]: ");
        getchar();
        ch=getchar();
        if(ch=='n') flag=false;
     }while(flag);
return 0;
}
