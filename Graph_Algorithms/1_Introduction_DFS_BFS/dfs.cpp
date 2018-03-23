#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>g[], int n, int s)
{
    int visited[n+1],i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    stack<int>st;
    st.push(s);
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        cout<<s<<" ";
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
                st.push(g[s][i]);
        }
    }
    cout<<endl;
}

int main()
{
    int n, m, i, a, b, s;
    cin>>n>>m;
    vector<int>g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    s=1;
    dfs(g, n, s);
    return 0;
}
