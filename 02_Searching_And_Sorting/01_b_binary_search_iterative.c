#include<stdio.h>

int search_binary_itr(int*a,int lb,int ub,int tar)
{
    int mid;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==tar)
            return mid;
        else if(a[mid]>tar)
            ub=mid-1;
        else
            lb=mid+1;
    }
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10},n=10,tar=9;
    printf("The cal %d is in location %d.\n",tar,search_binary_itr(a,0,n-1,tar));
    return 0;
}
