/*
        02_e_heap_sort.c

        this is the implementation of the heap sort
        algorithm, the idea over here is to create a heap
        and manipulate it to get the sorted array.

        the heap over here is implemented as an array.
*/

#include<stdio.h>


/*
        this function, heapify takes the array 'a', the length of
        the array 'n', the position to be heapified 'i', it considers
        the sub trees originating from that index(left and right children)
        as heaps, and makes the complete tree as a heap, by putting
        the root value at its correct position.
*/
void heapify(int*a,int n,int i)
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
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

/*
        Given an array, this function converts it to a heap.
*/
void make_heap(int*a,int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        heapify(a,n,i);
}

/*
        This is where sorting takes place.
*/
void heap_sort(int*a,int n)
{
    make_heap(a,n);
    int i,temp;
    for(i=1;i<n;i++)
    {
        temp=a[1];
        a[1]=a[n-i+1];
        a[n-i+1]=temp;
        heapify(a,n-i,1);
    }
}

int main()
{
    int a[11]={0,10,9,8,7,6,5,4,3,2,1},n=10,i;
    heap_sort(a,n);
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}
