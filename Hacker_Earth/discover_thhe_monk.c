#include <stdio.h>

int a[100005];

void heapify(int n,int i)
{
    if((i<<1)>n)
        return;
    int largest=i,temp;
    if(a[(i<<1)]>a[largest])
        largest=(i<<1);
    if((i<<1)+1<=n && a[(i<<1)+1]>a[largest])
        largest=(i<<1)+1;
    if(i!=largest)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(n,largest);
    }
}

inline void make_heap(int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        heapify(n,i);
}

inline void heap_sort(int n)
{
    int i, temp;
    make_heap(n);
    for(i=1;i<n;i++)
    {
        temp=a[1];
        a[1]=a[n-i+1];
        a[n-i+1]=temp;
        heapify(n-i,1);
    }
}

int bin_search(int lb,int ub, int tar)
{
    if(lb>=ub)
    {
        if(a[lb]==tar)
            return lb;
        return -1;
    }
    int mid=lb+(ub-lb)/2;
    if(a[mid]==tar)
        return mid;
    if(a[mid]>tar)
        return bin_search(lb,mid-1,tar);
    return bin_search(mid+1,ub,tar);
}

int main()
{
    int n,q,temp,i;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heap_sort(n);
    for(i=1;i<=q;i++)
    {
        scanf("%d",&temp);
        temp=bin_search(1,n,temp);
        if(temp==-1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
