#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int> g[] , int s, int n)
{
    int visited[100005];
    for(int i=1;i<=n;i++)
        visited[i]=0;
    queue <int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        s=q.front();
        cout<<s<<" ";
        q.pop();
        for(int i=1;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                q.push(g[s][i]);
                visited[g[s][i]]=1;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int n,temp,i,j;
    cin>>n;
    vector <int> g[n+1];
    for(i=1;i<=n;i++)
    {
        g[i].push_back(0);
        for(j=1;j<=n;j++)
        {
            cin>>temp;
            if(temp==1)
                g[i].push_back(j);
        }
    }

    bfs(g,5,n);
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
