#include<bits/stdc++.h>

using namespace std;

int* level(vector <int> g[], int n, int s)
{
    int*level=(int*)malloc(sizeof(int)*(n+1));
    int visited[n+1],i;
    for(i=1;i<=n;i++)
        level[i]=visited[i]=0;
    queue <int> q;
    q.push(s);
    visited[s]=1;
    level[s]=1;
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
                level[g[s][i]]=level[s]+1;
            }
        }
    }
    return level;
}

int main()
{
    int n,m,i,s,a,b,*lvl;
    cin>>n>>m;
    vector <int> g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>s;
    lvl=level(g,n,s);
    for(i=1;i<=n;i++)
        cout<<lvl[i]<<" ";
    cout<<endl;
    return 0;
}


