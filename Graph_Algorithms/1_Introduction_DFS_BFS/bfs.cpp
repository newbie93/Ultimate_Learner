#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int>g[], int n, int s)
{
    int visited[n+1],i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        visited[s]=1;
        cout<<s<<" ";
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
                q.push(g[s][i]);
        }
    }
    cout<<endl;
}

int main()
{
    int n, m, a, b, i, s;
    cin>>n>>m;
    vector<int>g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    s=1;
    bfs(g, n, s);
    return 0;
}
