
/*
        k_th_largest_2.c

        This is the another method of finding the kth largest element.
        We make a Min Heap of size K with the first K elements of array.
        For the next (N-K) elements. We compare whether they are greater
        than the root of the heap, if they are, then we remove the root,
        and insert that element as the root, and call heapify.

        thus ultimately we are left with a Heap, containing only the K
        largest elements in the Heap, with Kth largest elemenet being root
        of the Heap.
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void heapify(int *a,int n,int i)
{
    if(i*2>n)
        return;
    int smallest=i,temp;
    if(a[i*2]<a[smallest])
        smallest=i*2;
    if(i*2+1<=n && a[i*2+1]<a[smallest])
        smallest=i*2+1;
    if(i!=smallest)
    {
        temp=a[i];
        a[i]=a[smallest];
        a[smallest]=temp;
        heapify(a,n,smallest);
    }
}

void heap_insert(int *a,int *n,int val)
{
    *n=*n+1;
    int k=*n;
    while(k>1)
    {
        if(a[k/2]>val)
            a[k]=a[k/2];
        else
            break;
        k/=2;
    }
    a[k]=val;
}

int find_kth_largest(int*a,int n,int k)
{
    assert(a!=NULL && k<=n && k>0);
    int*t=(int*)malloc(sizeof(int)*(k+1));
    int size=0,i;
    for(i=1;i<=k;i++)
        heap_insert(t,&size,a[i]);
    for(i=k+1;i<=n;i++)
    {
        if(t[1]<a[i])
        {
            t[1]=a[i];
            heapify(t,size,1);
        }
    }
    return t[1];
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},k=3,n=10;
    printf("%d largest is %d\n",k,find_kth_largest(a,n,k));
    return 0;
}
