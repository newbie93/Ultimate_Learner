#include<stdio.h>

void bubble(int*a, int n)
{
    int i,j,temp,chk=1;
    for(i=0;i<n-1 && chk;i++)
    {
        chk=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                chk=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int traverse(int*a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[6]={0,6,8,4,2,10},n=6;
    bubble(a,n);
    traverse(a,n);
    return 0;
}
