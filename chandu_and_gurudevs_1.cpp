#include <bits/stdc++.h>

#define MAX -1
#define MOD 1000000007

using namespace std;

void dfs(vector< pair<int,int> >g[], int visited[], int s, int maximum)
{
    int i,vert,cost;
    visited[s]=1;
    for(i=0;i<g[s].size();i++)
    {
        vert=g[s][i].first;
        cost=g[s][i].second;
        if(maximum)
        if(visited[vert]==0)
            dfs(g, visited, vert, maximum);
    }
}

int main()
{
    int max_edge[201][201];
    int t,n,i,j,k,a,b,c;
    unsigned long long int sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                max_edge[i][j]=MAX;
        }
        for(i=1;i<n;i++)
        {
            cin>>a>>b>>c;
            max_edge[a][b]=c;
            max_edge[b][a]=c;
        }
        sum=0llu;
        /*for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(max_edge[i][k]>MAX && max_edge[k][j]>MAX)
                    {
                        max_edge[i][j]=max(max(max_edge[i][k],max_edge[k][j]),max_edge[i][j]);
                    }
                }
            }
        }*/
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
                cout<<max_edge[i][j]<<" ";
            cout<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}

