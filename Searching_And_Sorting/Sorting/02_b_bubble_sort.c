/*
        02_b_bubble_sort.c

        here bubble sort has been implemented.
        Its the simplest of all the comparision based sorts.
        Where we just compare between elements and swap, till
        we move the highest in every round to the end of our
        current unsorted segment of the array.
*/

#include<stdio.h>


void bubble_sort(int*a,int n)
{
    int i,j,temp,need=1;
    for(i=0;i<n-1 && need==1;i++)
    {
        need=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                need=1;
            }
        }
    }
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},n=10,i;
    bubble_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}
