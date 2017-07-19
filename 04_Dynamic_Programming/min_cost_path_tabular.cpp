#include<bits/stdc++.h>

#define ARR_MAX 10005
#define MAX 1000000009

using namespace std;

int arr[ARR_MAX][ARR_MAX];

int min_cost_path(int n, int m)
{
    int table[n+1][m+1],i,j;
    for(i=0;i<=m;i++)
        table[0][i]=MAX;
    for(i=0;i<=n;i++)
        table[i][0]=MAX;
    table[0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            table[i][j]=min(min(table[i-1][j-1],table[i-1][j]),table[i][j-1])+arr[i][j];
    }
    return table[n][m];
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cin>>arr[i][j];
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<min_cost_path(i,j)<<endl;
    }

    return 0;
}
