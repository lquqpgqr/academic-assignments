#include<stdio.h>

int num[100];

void QUICKSORT(int f,int l)
{
    int i,j,temp;
    if(f<l)
    {
        i=f+1;
        j=l;
        while(num[i]<num[f])
        {
            i++;
        }
        while(num[j]>num[f])
        {
            j--;
        }
        while(i<j)
        {
            temp=num[j];
            num[j]=num[i];
            num[i]=temp;
            while(num[i]<=num[f])
            {
                i++;
            }
            while(num[j]>=num[f])
            {
                j--;
            }
        }
        temp=num[f];
        num[f]=num[j];
        num[j]=temp;
        QUICKSORT(f,j-1);
        QUICKSORT(j+1,l);
    }

}


int main()
{
    int n,i;
    printf("Enter the numbers to sort: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }

    QUICKSORT(0,n-1);
    for(i=0; i<n; i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}

