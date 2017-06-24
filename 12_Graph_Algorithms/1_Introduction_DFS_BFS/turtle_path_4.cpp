#include <bits/stdc++.h>
#include <cmath>

#define MOD 1000000007

using namespace std;

int is_prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int count_path(int**g,int**visited,int**cost,int i,int j,int n,int m,int**path,int ptr,int *path_length)
{
    if(visited[i][j]==1)
        return cost[i][j];

    if(*path_length==0)
    {
        path[ptr][0]=i;
        path[ptr][1]=j;
    }

    if(i==n && j==m)
    {
        *path_length=ptr+1;
        cost[i][j]=1;
        visited[i][j]=1;
        return 1;
    }


    int ways = 0;

    if(i<n && j<m && g[i+1][j+1] == 1)
        ways = count_path(g,visited,cost,i+1,j+1,n, m, path, ptr+1, path_length)%MOD;

    if(i<n && g[i+1][j] == 1)
        ways = ( ways + count_path(g,visited,cost,i+1,j,n, m, path, ptr+1, path_length)%MOD )%MOD;

    if(j<m && g[i][j+1] == 1)
        ways = ( ways + count_path(g,visited,cost,i,j+1,n, m, path, ptr+1, path_length)%MOD )%MOD;

    cost[i][j]=ways;
    visited[i][j]=1;

    return ways;
}

int main()
{
    int n,m,i,j,t,path_length=0;

    cin>>n>>m;

    int **g = (int**)malloc(sizeof(int*)*1001);
    int **cost = (int**)malloc(sizeof(int*)*1001);
    int **visited = (int**)malloc(sizeof(int*)*1001);
    int **path = (int**)malloc(sizeof(int*)*1001);

    path[0]=(int*)malloc(sizeof(int)*2);

    for(i=1;i<=n;i++)
    {
        g[i]=(int*)malloc(sizeof(int)*1001);
        cost[i]=(int*)malloc(sizeof(int)*1001);
        visited[i]=(int*)malloc(sizeof(int)*1001);
        path[i]=(int*)malloc(sizeof(int)*2);
        for(j=1;j<=m;j++)
        {
            cin>>t;
            g[i][j]=is_prime(t);
            visited[i][j]=cost[i][j]=0;
        }
    }

    if(g[1][1]==0 || g[n][m]==0)
        cout<<"0\n";
    else if(n==1 && m==1)
        cout<<"1\n1 1\n";
    else
    {
        cout<<count_path(g,visited,cost,1,1,n,m,path,0,&path_length)<<endl;
        if(path_length>0)
        {
            for(i=0;i<path_length;i++)
                cout<<path[i][0]<<" "<<path[i][1]<<endl;
        }
    }
    return 0;
}

