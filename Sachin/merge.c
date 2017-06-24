#include <stdio.h>
#include <stdlib.h>

void merge(int*a,int*t,int lb,int mid,int ub)
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

void merge_sort(int*a,int *t,int lb,int ub)
{
    if(lb>=ub)
        return;
    int mid=lb+(ub-lb)/2;
    merge_sort(a,t,lb,mid);
    merge_sort(a,t,mid+1,ub);
    merge(a,t,lb,mid,ub);
}

int main()
{
    int t,n,i,*a,*b;
    a=(int*)malloc(sizeof(int)*100001);
    b=(int*)malloc(sizeof(int)*100001);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        merge_sort(a,b,0,n-1);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}

