#include<stdio.h>

void merge(int*a,int lb,int mid,int ub,int*t)
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
    for(i=lb;i<=ub;i++)\
        a[i]=t[i];
}

void merge_sort(int*a,int lb,int ub,int*t)
{
    if(lb>=ub)
        return;
    int mid=(ub+lb)/2;
    merge_sort(a,lb,mid,t);
    merge_sort(a,mid+1,ub,t);
    merge(a,lb,mid,ub,t);
}

int main()
{
    int t[10],a[10]={10,9,8,7,6,5,4,3,2,1},lb=0,ub=9,i;
    merge_sort(a,lb,ub,t);
    for(i=lb;i<=ub;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}

