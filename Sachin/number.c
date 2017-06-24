#include<stdio.h>
#include<stdlib.h>

inline int max(int a,int b)
{
    if(a<b)
        return b;
    return a;
}

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int grid[1000][1000];

int possible(int*a,int n,int val)
{
    qsort(&a[1],n,sizeof(int),comp);
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=val;j++)
        {
            if(a[i]==j)
                grid[i][j]=1;
            else if(a[i]<j)
            {
                if(grid[i][j-a[i]]>0)
                    grid[i][j]=max(grid[i-1][j],1+grid[i][j-a[i]]);
                else
                    grid[i][j]=grid[i-1][j];
            }
            else
                grid[i][j]=grid[i-1][j];
        }
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=val;j++)
            printf("%d ",grid[i][j]);
        puts("");
    }*/
    for(i=val;i>=0;i--)
        if(grid[n][i]>0)
            return i;
    return 0;
}

int main()
{
    int a[1000],t,n,val,i,j;
    scanf("%d",&t);
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
            grid[i][j]=0;
    }
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&val);
        printf("Max possible:- %d\n",possible(a,n,val));
    }
    return 0;
}
