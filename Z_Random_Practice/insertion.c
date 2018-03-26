#include<stdio.h>

void insertion(int*a, int n)
{
    int i,j,temp,ptr;
    for(i=1;i<n;i++)
    {
        ptr=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>ptr)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=ptr;
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
    insertion(a,n);
    traverse(a,n);
    return 0;
}
