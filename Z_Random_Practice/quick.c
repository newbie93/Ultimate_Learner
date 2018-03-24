#include<stdio.h>

int part(int*a, int lb, int ub)
{
    int i=lb-1,j=lb,pivot=a[ub],temp;
    while(j<ub)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        j++;
    }
    i++;
    a[ub]=a[i];
    a[i]=pivot;
    return i;
}

void quick_sort(int*a, int lb, int ub)
{
    if(lb>=ub)
        return;
    int j=part(a,lb,ub);
    quick_sort(a,lb,j-1);
    quick_sort(a,j+1,ub);
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
    quick_sort(a,0,n-1);
    traverse(a,n);
    return 0;
}
