#include <stdio.h>
#include <stdlib.h>

int **path;

int *visited;

int *st;

int **g;

int *ptr_g;

int list[100001];

int top=-1;

void push_back(int val)
{
    list[++top]=val;
}

int get_size()
{
    return top;
}

void clear()
{
    top=-1;
}

void set_top(int val)
{
    top=val;
}

int is_empty()
{
    if(top==-1)
        return 1;
    return 0;
}

int get_int()
{
    int n=0,c;
    while((c=getchar())>='0' && c<='9')
        n=(n<<3)+(n<<1)+c-'0';
    return n;
}

void mark_children(int s)
{
    visited[s]=1;
    push_back(s);
    int lb=get_size(),ub,i;
    for(i=0;g[s][i]!=-1;i++)
    {
        if(visited[g[s][i]]==0)
            mark_children(g[s][i]);
    }
    ub=get_size();
    for(i=lb+1;i<=ub;i++)
        path[s][list[i]]=1;
}

int main()
{

    int n,a,b,c,q,i,j;
    n=get_int();

    g=(int**)malloc(sizeof(int*)*(n+1));
    path=(int**)malloc(sizeof(int*)*(n+1));
    visited=(int*)malloc(sizeof(int)*(n+1));
    ptr_g=(int*)malloc(sizeof(int)*(n+1));

    for(i=0;i<=n;i++)
    {
        g[i]=(int*)malloc(sizeof(int)*(n+1));
        path[i]=(int*)malloc(sizeof(int)*(n+1));
        visited[i]=0;
        ptr_g[i]=0;

        for(j=0;j<=n;j++)
        {
            g[i][j]=-1;
            path[i][j]=0;
        }
    }

    for(i=1;i<n;i++)
    {
        a=get_int();
        b=get_int();
        g[a][ptr_g[a]++]=b;
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            mark_children(i);
            clear();
        }
    }
    q=get_int();
    for(i=1;i<=q;i++)
    {
        a=get_int();
        b=get_int();
        c=get_int();

        if(a==0)
        {
            if(path[b][c]==1)
                puts("YES");
            else
                puts("NO");
        }
        else
        {
            if(path[c][b]==1)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}

