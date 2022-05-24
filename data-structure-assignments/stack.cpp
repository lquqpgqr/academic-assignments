#include<stdio.h>
int n,x;
int top=-1;
int arr[50];
void push(int item){
    if(top!=n-1){
        top++;
        arr[top]=item;
        printf("top:%d\n",top);
        }
        else {
                printf("Stack is Full.\n");
                printf("top:%d\n",top);
        }
}
int pop(){
    if(top!=-1){
        x=arr[top];
        top--;
        printf("top:%d\n",top);
        return x;
    }
}
int main(){
     printf("Enter Stack size 1~50:");
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
            if(top!=-1){
                popped=pop();
                printf("%d\n",popped);
            }
            else {
                printf("Stack is empty.\n");
                printf("top:%d\n",top);
            }

        }
        printf("again?[enter/n]: ");
        getchar();
        ch=getchar();
        if(ch=='n') flag=false;
     }while(flag);
return 0;
}

