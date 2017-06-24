#include<bits/stdc++.h>

#define Vertex first
#define Limit second

using namespace std;

int bfs(vector < pair<int,int> > g[],int n,int s)
{
    int visited[n+1],level[n+1],i;
    for(i=1;i<=n;i++)
        visited[i]=level[i]=0;
    queue<int>q;
    q.push(s);
    visited[s]=1;
    level[s]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i].Vertex]==0 && g[s][i].Limit>level[s])
            {
                q.push(g[s][i].Vertex);
                visited[g[s][i].Vertex]=1;
                level[g[s][i].Vertex]=level[s]+1;
                if(g[s][i].Vertex==n)
                    return level[g[s][i].Vertex];
            }
        }
    }
    return -1;
}

int main()
{
    int n,m,t,i,a,b;
    cin>>n>>m>>t;

    if(n==0)
    {
        printf("0\n");
        return 0;
    }

    vector < pair<int,int> > g[n+1];

    int aa[m+1][3];

    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        aa[i][0]=a;
        aa[i][1]=b;
        aa[i][2]=1000000009;
    }

    for(i=1;i<=t;i++)
    {
        cin>>b>>a;
        aa[a][2]=b;
    }

    for(i=1;i<=m;i++)
    {
        g[aa[i][0]].push_back(make_pair(aa[i][1],aa[i][2]));
        g[aa[i][1]].push_back(make_pair(aa[i][0],aa[i][2]));
    }

    cout<<bfs(g,n,1)<<endl;

    return 0;
}
