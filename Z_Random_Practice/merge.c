#include<stdio.h>

void merge(int*a, int*t, int lb, int mid, int ub)
{
    int i=lb,j=mid+1,k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];
    }
    while(i<=mid)
        t[k++]=a[i++];
    while(j<=ub)
        t[k++]=a[j++];
    for(i=lb;i<=ub;i++)
        a[i]=t[i];
}

void merge_sort(int*a, int*t, int lb, int ub)
{
    if(lb>=ub)
        return;
    int mid=lb+(ub-lb)/2;
    merge_sort(a, t, lb, mid);
    merge_sort(a, t, mid+1, ub);
    merge(a, t, lb, mid, ub);
}

int traverse(int*a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[6]={0,6,8,4,2,10},t[6],n=6;
    merge_sort(a,t,0,n-1);
    traverse(a,n);
    return 0;
}
