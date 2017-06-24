#include <bits/stdc++.h>

#define Vertex first
#define Cost second

using namespace std;

pair<int,int> max_cost(vector< pair<int,int> >g[],int n,int s)
{
    int i,visited[n+1],cost[n+1],max_cost=0;
    pair<int,int>p;
    for(i=1;i<=n;i++)
        visited[i]=cost[i]=0;
    queue <int>q;
    q.push(s);
    visited[s]=1;
    p.Vertex=s;
    p.Cost=max_cost;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i].Vertex]==0)
            {
                q.push(g[s][i].Vertex);
                visited[g[s][i].Vertex]=1;
                cost[g[s][i].Vertex]=cost[s]+g[s][i].Cost;
                if(max_cost<cost[g[s][i].Vertex])
                {
                    max_cost=cost[g[s][i].Vertex];
                    p.Vertex=g[s][i].Vertex;
                    p.Cost=max_cost;
                }
            }
        }
    }
    return p;
}

int main()
{
    int t,n,a,b,c,i,max;
    pair <int,int>p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector < pair <int,int> > g[n+1];
        for(i=1;i<n;i++)
        {
            cin>>a>>b>>c;
            g[a].push_back(make_pair(b,c));
            g[b].push_back(make_pair(a,c));
        }
        max=0;
        p=max_cost(g,n,i);
        p=max_cost(g,n,p.Vertex);
        max=p.Cost;
        if(max>10000)
            c=10000;
        else if(max>1000)
            c=1000;
        else if(max>100)
            c=100;
        else
            c=0;
        cout<<c<<" "<<max<<endl;

    }
    return 0;
}

