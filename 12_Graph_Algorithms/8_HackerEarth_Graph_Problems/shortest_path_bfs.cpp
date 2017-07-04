#include<bits/stdc++.h>

/*
    this is for directed graphs
*/

using namespace std;

void bfs_shortest_path(vector<int>g[],int cost[],int n,int s)
{
    int i,visited[n+1];
    for(i=1;i<=n;i++)
        visited[i]=0;
    queue <int>q;
    q.push(s);
    visited[s]=1;
    cost[s]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                q.push(g[s][i]);
                visited[g[s][i]]=1;
                cost[g[s][i]]=cost[s]+1;
            }
        }
    }
}

int main()
{
    int n,m,i,a,b,s;
    cin>>n>>m;
    vector <int> g[n+1];
    int cost[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    cin>>s;
    bfs_shortest_path(g,cost,n,s);
    for(i=1;i<=n;i++)
        cout<<cost[i]<<" ";
    cout<<endl;
    return 0;
}
