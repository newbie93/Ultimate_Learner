/*
7 7
1 3
2 3
3 5
2 4
5 6
4 6
6 7

*/


#include<bits/stdc++.h>

using namespace std;

int* topological_sort(vector<int>g[], int n)
{
    int indegree[n+1],i,j,s,*sorted;
    sorted=(int*)malloc(sizeof(int)*(n+1));
    for(i=1;i<=n;i++)
        indegree[i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<g[i].size();i++)
            indegree[g[i][j]]++;
    }
    queue<int>q;
    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    j=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        sorted[j++]=s;
        for(i=0;i<g[s].size();i++)
        {
            if(--indegree[g[s][i]]==0)
                q.push(g[s][i]);
        }
    }
    return sorted;
}

int main()
{
    int n,m,i,a,b;
    cin>>n>>m;
    vector<int>g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    int*sorted=topological_sort(g, n);
    for(i=1;i<=n;i++)
        cout<<sorted[i]<<" ";
    cout<<endl;
    return 0;
}
