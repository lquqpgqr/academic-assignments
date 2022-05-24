#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int arr[100],comparing[3]={0,0,0},swaping[3]={0,0,0};
double diff[3]={0,0,0};
int n=10;
bool flag=false;
void bubbleSort(int array1[]){
    time_t start,end;
    time (&start);
    int ar[100];
    for(int i=1; i<=n; i++){
        ar[i]=array1[i];
    }
    printf("\nThis is from Bubble shot:\n");
    int j,temp;
    int z=n;
    while(z!=0){
        int t=0;
        for(j=1;j<=z-1;j++){
            comparing[0]++;
            if(ar[j]>ar[j+1]){
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
                t=j;
                swaping[0]+=3;
            }
        }z=t;
    }
    for(j=1; j<=n; j++){
        printf("%d\t",ar[j]);
    }
    printf("\n");
    time (&end);
    diff[0] = difftime (end,start);

}
void insertionShot(int array1[]){
    time_t start,end;
    time (&start);
    printf("\nThis is from Insertion Shot:\n");
    int temp,i,j;
    int ar[100];
        for(int i=1; i<=n; i++){
        ar[i]=array1[i];
    }
    ar[0]=(int)-pow(2,32);
    for(j=2;j<=n;j++){
        temp=ar[j];
        i=j-1;
        while(temp<ar[i]){
            comparing[1]+=1;
            swaping[1]+=1;
            ar[i+1]=ar[i];
            i=i-1;
        }ar[i+1]=temp;
        swaping[1]+=1;
    }
    for(j=1; j<=n; j++){
        printf("%d\t",ar[j]);
    }
    printf("\n");
    time (&end);
    diff[1] = difftime (end,start);

}
void selection(int array1[]){
    time_t start,end;
    time (&start);
    printf("\nThis is from selection Shot:");
    int temp,j,k;
    int ar[100];
    for(int i=1; i<=n; i++){
        ar[i]=array1[i];
    }
    for(j=n;j>=2;j--){
        int t=1;
        for(k=2;k<=j;k++){
            comparing[2]+=1;
            if(ar[t]<ar[k]){
                t=k;
            }
        }   temp=ar[j];
            ar[j]=ar[t];
            ar[t]=temp;
            swaping[2]+=1;
    }
    printf("\n");
    for(j=1; j<=n; j++){
            arr[j]=ar[j];
        printf("%d\t",ar[j]);
    }
    time (&end);
    printf("\n");
    diff[2] = difftime (end,start);
}

void binary(int ar[],int element){
    int mid, high=n, low=1;
    while(high>=low){
        mid=(high+low)/2;
        if(ar[mid]==element){
            flag=true;
            break;
        }else if(ar[mid]>element)
             high=mid-1;
             else if(ar[mid]<element)
                low=mid+1;
    }if(flag==1)
        printf("\nElement found at position %d",mid);
    else
        printf("\nElement not found");
}

int main(){
    int i,element;
    srand(time(0));
    printf("A random array:\n");
    for(i=1; i<=n;i++){
        arr[i]=rand();
    }
    for(i=1; i<=n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    bubbleSort(arr);
    insertionShot(arr);
    selection(arr);

    printf("\nMovement\tComparison\tTime\n");
    printf("%d\t\t%d\t\t%d\n",swaping[0],comparing[0],diff[0]);
    printf("%d\t\t%d\t\t%d\n",swaping[1],comparing[1],diff[1]);
    printf("%d\t\t%d\t\t%d\n",swaping[2],comparing[2],diff[2]);

    printf("\nEnter searching element: ");
    scanf("%d",&element);
    binary(arr,element);

return 0;
}
