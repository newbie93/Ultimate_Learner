#include<stdio.h>

void selection(int*a, int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

int traverse(int*a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[6]={0,6,8,4,2,10},n=6;
    selection(a,n);
    traverse(a,n);
    return 0;
}
