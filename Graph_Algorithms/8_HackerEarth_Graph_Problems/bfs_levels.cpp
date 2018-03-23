#include<bits/stdc++.h>

using namespace std;

int bfs_level_count(vector<int> g[] , int s, int n)
{
    int visited[100005],cnt=0;
    for(int i=1;i<=n;i++)
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
            cnt++;
            if(!q.empty())
                q.push(0);
        }
        else
        {
            for(int i=1;i<g[s].size();i++)
            {
                if(visited[g[s][i]]==0)
                {
                    q.push(g[s][i]);
                    visited[g[s][i]]=1;
                }
            }
        }
    }
    return cnt;
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

    cout<<bfs_level_count(g,1,n)<<endl;
    return 0;
}

/*
5
0 1 1 1 0
1 0 1 0 0
1 1 0 1 1
1 0 1 0 1
0 0 1 1 0

*//*
5
0 1 0 0 0
1 0 1 0 0
0 1 0 1 0
0 0 1 0 1
0 0 0 1 0

*/

