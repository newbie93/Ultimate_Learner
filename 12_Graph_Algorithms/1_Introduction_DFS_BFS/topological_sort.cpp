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

void explore_deapths(vector<int>g[], int s, int visited[], stack<int>&st)
{
    visited[s]=1;
    for(int i=0;i<g[s].size();i++)
    {
        if(visited[g[s][i]]==0)
            explore_deapths(g, g[s][i], visited, st);
    }
    st.push(s);
}

void topological_sort(vector<int>g[], int n)
{
    int visited[n+1],i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    stack<int>st;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            explore_deapths(g, i, visited, st);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    int n, m, i, a, b;
    cin>>n>>m;
    vector<int>g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    topological_sort(g,n);
    return 0;
}
