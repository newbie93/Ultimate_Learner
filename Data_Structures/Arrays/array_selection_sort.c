#include<stdio.h>

void selection_sort(int*a, int n)
{
    int i,j,min_index,temp;
    for(i=0;i<n;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
                min_index=j;
        }
        temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
    }
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
    int a[6]={5,4,3,2,1,0},n=6,i;
    selection_sort(a,n);
    traverse(a,n);
    return 0;
}
