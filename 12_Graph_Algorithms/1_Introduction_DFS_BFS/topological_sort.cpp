#include<bits/stdc++.h>

using namespace std;

stack <int> st;

void find_children(vector <int>g[],int visited[],int s)
{
    int i;
    visited[s]=1;
    for(i=0;i<g[s].size();i++)
    {
        if(visited[g[s][i]]==0)
            find_children(g,visited,g[s][i]);
    }
    st.push(s);
}

void topological_sort(vector <int>g[],int n)
{
    int i,visited[n+1];
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            find_children(g,visited,i);
    }
}

int main()
{
    int n,m,a,b,i;
    cin>>n>>m;
    vector <int> g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    topological_sort(g,n);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
