#include<bits/stdc++.h>

using namespace std;

int level(vector <int> g[], int n, int s)
{
    int visited[n+1],i,level=0;
    for(i=1;i<=n;i++)
        visited[i]=0;
    queue <int> q;
    q.push(s);
    q.push(0);
    visited[s]=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        if(s==0)
        {
            level++;
            if(q.empty())
                break;
            q.push(0);
        }
        else
        {
            for(i=0;i<g[s].size();i++)
            {
                if(visited[g[s][i]]==0)
                {
                    q.push(g[s][i]);
                    visited[g[s][i]]=1;
                }
            }
        }
    }
    return level;
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
    cout<<level(g,n,s)<<endl;
    return 0;
}

