#include <bits/stdc++.h>

using namespace std;

int min_cost(vector <int> g[], int n, int s)
{
    int i,visited[n+1],level[n+1];

    for(i=1;i<=n;i++)
        level[i]=visited[i]=0;

    queue <int> q;
    q.push(s);
    level[s]=0;
    visited[s]=1;

    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                q.push(g[s][i]);
                visited[g[s][i]]=0;
                level[g[s][i]]=level[s]+1;
                if(g[s][i]==n)
                    break;
            }
        }
        if(i<g[s].size())
            break;
    }

    return level[n];
}

int main()
{
    int t,n,m,a,b,i;
    vector <int> g[10001];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout<<min_cost(g,n,1)<<endl;
        //for(i=1;i<=n;i++)
        //    g[i].clear();
    }
    return 0;
}
