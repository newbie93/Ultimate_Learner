#include<stdio.h>

int partition(int *a, int lb, int ub)
{
    int i=lb-1,j=lb,pivot=a[ub],temp;
    while(j<ub)
    {
        if(a[j]<pivot)
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
        j++;
    }
    i++;
    a[ub]=a[i];
    a[i]=pivot;
    return i;
}

void quick_sort(int *a, int lb, int ub)
{
    if(lb>=ub)
        return;
    int j=partition(a, lb, ub);
    quick_sort(a, lb, j-1);
    quick_sort(a, j+1, ub);
}

void traverse(int*a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int a[6]={5,4,3,2,1,0},lb=0,ub=5,i;
    quick_sort(a,lb,ub);
    traverse(a,ub+1);
    return 0;
}
