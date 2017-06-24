#include<bits/stdc++.h>

using namespace std;

int dfs(vector<int>g[],int s,int n,int m)
{
    int visited[n+1],i,count=0;

    for(int i=1;i<=n;i++)
        visited[i]=0;

    stack <int> stck;
    stck.push(s);
    visited[s]=1;

    while(!stck.empty())
    {
        s=stck.top();
        stck.pop();
        count++;
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                stck.push(g[s][i]);
                visited[g[s][i]]=1;
            }
        }
    }

    return (n-count);
}

int main()
{

    int n,m,x,i,a,b;
    cin>>n>>m;
    vector <int> g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>x;
    cout<<dfs(g,x,n,m);
    return 0;
}

/*
5
0 1 1 1 0
1 0 1 0 0
1 1 0 1 1
1 0 1 0 1
0 0 1 1 0

*/


