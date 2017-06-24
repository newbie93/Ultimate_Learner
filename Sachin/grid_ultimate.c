#include<stdio.h>
#include<stdlib.h>

void find_max_common(int**a,int i,int j,int common,int moves)
{
    if(moves>100000)
        return;
    if(i>1)

}

int main()
{
    int**a;
    int n,i,j,i_0,j_0,common=0;
    scanf("%d",&n);
    a=(int**)malloc(sizeof(int*)*(n+1));
    for(i=1;i<=n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*(n+1));
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            {
               i_0=i;
               j_0=j;
            }
            if((n*(i-1)+j)==a[i][j])
                common++;
        }
    }
    find_max_common()
    return 0;
}
