#include<stdio.h>

void selection_sort(int*a,int n)
{
    int i,j,smallest,temp;
    for(i=0;i<n-1;i++)
    {
        smallest=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[smallest])
                smallest=j;
        }
        if(smallest!=i)
        {
            temp=a[i];
            a[i]=a[smallest];
            a[smallest]=temp;
        }
    }
}

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},n=10,i;
    selection_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}
