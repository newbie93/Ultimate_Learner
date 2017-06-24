#include <bits/stdc++.h>

using namespace std;

void lucky(vector<int>g[],int n,int s)
{
    int visited[n],luck[n],i;
    for(i=0;i<n;i++)
        visited[i]=luck[i]=0;
    queue <int>q;
    q.push(s);
    visited[s]=1;
    luck[s]=0;
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
                luck[g[s][i]]=luck[s]+1;
            }
        }
    }
    for(i=1;i<n;i++)
        cout<<luck[i]<<endl;
}

int main()
{
    int a,b,i,x,y;
    cin>>a>>b;
    vector <int>g[a];
    for(i=0;i<b;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lucky(g,a,0);
    return 0;
}

