/*
        02_d_merge_sort.c

        Here merge sort algorithm has been implemented.
        the idea behind merge sort is that, the problem
        is broken into smaller problems, and solved, and then
        combined to get the solution to the larger problem.

        The array is broken into smaller arrays.
        Then the smaller arrays are merged in sorted order.
*/

#include<stdio.h>


/*
        Here the smaller arrays are merged in sorted order.
*/
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

/*
        Here we divide the problem into smaller problems
        and solve them.
*/
void merge_sort(int*a,int lb,int ub,int*t)
{
    if(lb>=ub)
        return;
    //int mid=(ub+lb)/2;
    int mid=lb+(ub-lb)/2; // here there wont be a overflow
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

