#include<stdio.h>

int search_linear(int*a,int n,int tar)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==tar)
            return i;
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10},n=10,tar=5;
    printf("The cal %d is in location %d.\n",tar,search_linear(a,n,tar));
    return 0;
}
