
/*
        k_th_largest_2.c

        This is the another method of finding the kth largest element.
        Here we take the entire array and build a max heap out of it.
        and then take out the top element every time for K times, and
        heapify the rest.
*/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void heapify(int *a,int n,int i)
{
    if(i*2>n)
        return;
    int largest=i,temp;
    if(a[i*2]>a[largest])
        largest=i*2;
    if(i*2+1<=n && a[i*2+1]>a[largest])
        largest=i*2+1;
    if(i!=largest)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

void make_heap(int*a,int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        heapify(a,n,i);
}

int find_kth_largest(int*a,int n,int k)
{
    assert(a!=NULL && n>=k && k>0);
    int *temp=(int*)malloc(sizeof(int)*(n+1)),i,k_largest;
    for(i=1;i<=n;i++)
        temp[i]=a[i];
    make_heap(temp,n);
    for(i=1;i<=k;i++)
    {
        k_largest=temp[1];
        temp[1]=temp[n-i+1];
        heapify(temp,n-i,1);
    }
    return k_largest;
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},k=3,n=10;
    printf("%d largest is %d\n",k,find_kth_largest(a,n,k));
    return 0;
}
