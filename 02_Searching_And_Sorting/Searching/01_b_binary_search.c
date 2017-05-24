/*
        01_b_binary_search.c

        This is the implementation of Binary Search.
        Binary search always work on an array that is already
        sorted in some order. The idea here is to decrease our
        search space by half, after each round of search.
 */

#include<stdio.h>

/*      returns the position of the target, if found else -1
*/
int search_binary(int*a,int lb,int ub,int tar)
{
    if(lb>=ub)
    {
        if(lb==ub && a[lb]==tar)
            return lb;
        return -1;
    }
    //int mid=(lb+ub)/2;
    /*  mid=(lb+ub)/2
        the above method of finding the mid-point can cause
        overflow, so we modify the formula...
    */
    int mid=lb+(ub-lb)/2;
    if(a[mid]==tar)
        return mid;
    if(a[mid]>tar)
        return search_binary(a,lb,mid-1,tar);
    else
        return search_binary(a,mid+1,ub,tar);
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10},n=10,tar=10;
    printf("The cal %d is in location %d.\n",tar,search_binary(a,0,n-1,tar));
    return 0;
}
