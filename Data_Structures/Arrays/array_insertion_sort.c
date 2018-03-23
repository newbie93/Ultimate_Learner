#include<stdio.h>

void insertion_sort(int*a, int n)
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
    insertion_sort(a,n);
    traverse(a,n);
    return 0;
}
