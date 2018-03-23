#include <stdio.h>

int get_int()
{
    int n=0,c;
    while((c=getchar())>='0'&&c<='9')
        n=(n<<3)+(n<<1)+c-'0';
    return n;
}

int countries_burnt(int**a,int n,int m,int i,int j)
{
    if(a[i][j]==0)
        return 0;
    a[i][j]=0;
    int count=1;
    if(i>1 && a[i-1][j]==1)
        count+=countries_burnt(a,n,m,i-1,j);
    if(i<n && a[i+1][j]==1)
        count+=countries_burnt(a,n,m,i+1,j);
    if(j>1 && a[i][j-1]==1)
        count+=countries_burnt(a,n,m,i,j-1);
    if(j<m && a[i][j+1]==1)
        count+=countries_burnt(a,n,m,i,j+1);
    return count;
}

int main()
{
    int n,m,q,**a,i,j,x,y,countries=0;
    n=get_int();
    m=get_int();
    q=get_int();
    a=(int**)malloc(sizeof(int*)*(n+1));
    for(i=1;i<=n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*(m+1));
        for(j=1;j<=m;j++)
        {
            a[i][j]=get_int();
            if(a[i][j]==1)
                countries++;
        }
    }
    for(i=1;i<=q;i++)
    {
        x=get_int();
        y=get_int();
        countries-=countries_burnt(a,n,m,x,y);
        printf("%d\n",countries);
    }
    return 0;
}

