#include<bits/stdc++.h>

#define INF 1000000009

using namespace std;

void shortest_distance(vector<int>g[], int n, int s, int distance[])
{
    int i;
    for(i=1;i<=n;i++)
        distance[i]=INF;
    queue<int>q;
    q.push(s);
    distance[s]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<g[s].size();i++)
        {
            if(distance[g[s][i]]>distance[s]+1)
            {
                q.push(g[s][i]);
                distance[g[s][i]]=distance[s]+1;
            }
        }
    }
}

int main()
{
    int n, m, i, a, b, s;
    cin>>n>>m;
    int distance[n+1];
    vector<int>g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    s=1;
    shortest_distance(g, n, s, distance);
    for(i=2;i<=n;i++)
        cout<<distance[i]<<" ";
    cout<<endl;
    return 0;
}
