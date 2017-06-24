#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>g[],int s,int n)
{
    int visited[n],i;
    for(int i=1;i<=n;i++)
        visited[i]=0;
    stack <int> stck;
    stck.push(s);
    visited[s]=1;
    while(!stck.empty())
    {
        s=stck.top();
        cout<<s<<" ";
        stck.pop();
        for(i=1;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                stck.push(g[s][i]);
                visited[g[s][i]]=1;
            }
        }
    }
    cout<<"\n";
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

    dfs(g,1,n);
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

