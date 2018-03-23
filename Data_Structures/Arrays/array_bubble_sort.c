#include<stdio.h>

void bubble_sort(int*a, int n)
{
    int i,j,chk=1,temp;
    for(i=0;i<n-1 && chk;i++)
    {
        chk=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                chk=1;
            }
        }
        if(chk==0)
            break;
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
    bubble_sort(a,n);
    traverse(a,n);
    return 0;
}
