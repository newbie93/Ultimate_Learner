#include<bits/stdc++.h>

using namespace std;

queue<int>q;

void mark_all_children(vector<int>g[],int visited[])
{
    int i,s=q.front();
    q.pop();
    for(i=0;i<g[s].size();i++)
    {
        if(visited[g[s][i]]==0 && --indegree[g[s][i]]==0)
        {
            visited[g[s][i]]=1;
            q.push(g[s][i]);
            mark_all_children(g,visited);
        }
    }
}

int main()
{
    int n,m,a,b,i,s;
    cin>>n>>m;
    int indegree[n+1];
    int visited[n+1];
    vector <int> g[n+1];
    for(i=1;i<=n;i++)
        visited[i]=indegree[i]=0;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            visited[i]=1;
        }
    }


    return 0;
}
