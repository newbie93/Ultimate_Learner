#include<stdio.h>

void heapify(int*a, int n, int i)
{
    if(i*2>n)
        return;
    int largest=i,temp;
    if(a[i*2]>a[largest])
        largest=i*2;
    if(i*2+1<=n && a[i*2+1]>a[largest])
        largest=i*2+1;
    if(largest!=i)
    {
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,n,largest);
    }
}

void make_heap(int*a, int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        heapify(a,n,i);
}

void heap_sort(int*a, int n)
{
    int i,temp;
    make_heap(a,n);
    for(i=1;i<n;i++)
    {
        temp=a[1];
        a[1]=a[n-i+1];
        a[n-i+1]=temp;
        heapify(a, n-i, 1);
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
    int a[7]={-1,0,6,8,4,2,10},n=6;
    heap_sort(a,n);
    traverse(a,n+1);
    return 0;
}

