
#include<bits/stdc++.h>

using namespace std;

int bfs_level_count(vector<int> g[] , int s, int n, int k)
{
    int visited[n+1],lvl[n+1],cnt=0;

    for(int i=1;i<=n;i++)
        lvl[i]=visited[i]=0;

    queue <int> q;
    q.push(s);
    visited[s]=1;
    lvl[s]=1;

    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(int i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                q.push(g[s][i]);
                visited[g[s][i]]=1;
                lvl[g[s][i]]=lvl[s]+1;
                //cout<<g[s][i]<<" is at level "<<lvl[g[s][i]]<<endl;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(lvl[i]==k)
            cnt++;
    }

    return cnt;
}

int main()
{
    int n,i,a,b,k;
    cin>>n;
    vector <int> g[n+1];
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=0)
    }*/
    cin>>k;
    cout<<bfs_level_count(g,1,n,k)<<endl;
    return 0;
}
/*

20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2

*/

