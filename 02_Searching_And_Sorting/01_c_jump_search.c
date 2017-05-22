/*
        01_c_jump_search.c

        This is the implementation of Jump Search.
        Here a sorted array is sent, just like binary sort, this algorithm is also
        supplied with a sorted array. This method conducts lesser comparisions than
        linear search, but more than binary search.
        Here the performance depends on block size. the best performance is achieved when
        block size is sqrt(n).
 */

#include<stdio.h>
#include<math.h>

int jump_search(int*a,int n,int tar)
{
    int i,j,m=sqrt(n);// m is the block size
    for(i=m;i<n;)
    {
        if(a[i]>tar)
        {
            for(j=i-m;j<i;j++)
                if(a[j]==tar)
                    return j;
            if(j>=i)
                return -1;
        }
        if(i+m>=n)
        {
            for(j=i;j<n;j++)
                if(a[j]==tar)
                    return j;
            if(j>=n)
                return -1;
        }
        i+=m;
    }
}

int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 710, 810};
    int x = 3,n=18;
    printf("%d\n",jump_search(arr,n,x));
    return 0;
}
