#include<bits/stdc++.h>

using namespace std;

int num_connected_components(vector<int>g[], int n)
{
    int i, j, s, visited[n+1], c=0;
    for(i=1;i<=n;i++)
        visited[i]=0;
    stack<int>st;
    for(i=1;i<=n;i++)
    {
        if(visited[i]!=0)
            continue;
        c++;
        s=i;
        st.push(s);
        while(!st.empty())
        {
            s=st.top();
            st.pop();
            visited[s]=1;
            for(j=0;j<g[s].size();j++)
            {
                if(visited[g[s][j]]==0)
                    st.push(g[s][j]);
            }
        }
    }
    return c;
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
        g[b].push_back(a);
    }
    cout<<num_connected_components(g, n)<<endl;
    return 0;
}
