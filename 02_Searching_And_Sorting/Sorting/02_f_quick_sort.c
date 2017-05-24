/*
        02_f_quick_sort.c

        this is the implementation of the quick sort
        algorithm, the idea here is putting a particular
        element in its correct position
*/

#include<stdio.h>

int partition(int*a,int lb,int ub)
{
    int i=lb-1,j=lb,pivot=a[ub],temp;
    while(j<ub)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        j++;
    }
    i++;
    a[ub]=a[i];
    a[i]=pivot;
    return i;
}

void quick_sort(int*a,int lb,int ub)
{
    if(lb>=ub)
        return;
    int j=partition(a,lb,ub);
    quick_sort(a,lb,j-1);
    quick_sort(a,j+1,ub);
}

int main()
{
    int a[11]={0,10,9,8,7,6,5,4,3,2,1},n=11,i;
    quick_sort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}
