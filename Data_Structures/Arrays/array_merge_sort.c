#include<stdio.h>

int merge(int *a, int*t, int lb, int mid, int ub)
{
    int i=lb,k=lb,j=mid+1;
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
    merge_sort(a,t,lb,mid);
    merge_sort(a,t,mid+1,ub);
    merge(a,t,lb,mid,ub);
}

void traverse(int*a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int a[6]={5,4,3,2,1,0},t[6],lb=0,ub=5,i;
    merge_sort(a,t,lb,ub);
    traverse(a,ub+1);
    return 0;
}
