
/*
        k_th_largest_1.c

        This is the first method of finding the kth largest element.
        Here we sort the entire array, and just return the element
        at the wanted position.
*/

#include<stdio.h>
#include<assert.h>

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

int find_k_largest(int*a,int n,int k)
{
    assert(a!=NULL && n>=k && k>0);
    int*temp=(int*)malloc(sizeof(int)*n),i; // we dont want to manipulate the original array
    for(i=0;i<n;i++)
        temp[i]=a[i];
    quick_sort(temp,0,n-1); // sorting the array
    int val=temp[n-k];// the element at the Kth largest position
    free(temp);
    return val;
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},k=3,n=10;
    printf("%d largest is %d\n",k,find_k_largest(a,n,k));
    return 0;
}
