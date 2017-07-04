#include<bits/stdc++.h>

using namespace std;

void dfs(vector <int> g[], int n, int s)
{
    int visited[n+1],i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    stack <int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        s=q.top();
        q.pop();
        cout<<s<<" ";
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                q.push(g[s][i]);
                visited[g[s][i]]=1;
            }
        }
    }
    cout<<endl;
}

int main()
{
    int n,m,i,s,a,b;
    cin>>n>>m;
    vector <int> g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>s;
    dfs(g,n,s);
    return 0;
}

