#include<bits/stdc++.h>

using namespace std;

int no_of_edge(vector <int>g[],int degree[],int visited[],int s)
{
    int i,sum_of_degree=0;
    stack <int> st;
    st.push(s);
    visited[s]=1;
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        sum_of_degree+=degree[s];
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                st.push(g[s][i]);
                visited[g[s][i]]=1;
            }
        }
    }
    return (sum_of_degree>>1);
}

int main()
{
    int n,m,i,a,b,max_edge=0,t;
    cin>>n>>m;

    if(m==0)
    {
        cout<<"0\n";
        return 0;
    }

    int degree[n+1],visited[n+1];
    for(i=1;i<=n;i++)
        degree[i]=visited[i]=0;
    vector <int>g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            t=no_of_edge(g,degree,visited,i);
            if(t>max_edge)
                max_edge=t;
        }
    }
    cout<<max_edge<<endl;
    return 0;
}
