/*
        02_c_insertion_sort.c

        Here insertion sort has been implemented.

        the idea behind insertion sort is just like
        arranging a pack of cards in order.
        We take one card at a time and shift it to the
        left in its correct position, considering the left
        is already sorted.
*/

#include<stdio.h>

void insertion_sort(int*a,int n)
{
    int i,j,ptr;
    for(i=1;i<n;i++)
    {
        ptr=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>ptr)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=ptr;
    }
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},n=10,i;
    insertion_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}
