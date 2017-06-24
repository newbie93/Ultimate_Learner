#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int dfs_modify(vector <int>g[],int a[],int visited[],int s)
{
    int maximum=0,i,count_max=0;
    vector <int> know;
    stack <int> st;
    st.push(s);
    visited[s]=1;
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        if(maximum<a[s])
            maximum=a[s];
        know.push_back(a[s]);
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==0)
            {
                st.push(g[s][i]);
                visited[g[s][i]]=1;
            }
        }
    }
    for(i=0;i<know.size();i++)
    {
        if(know[i]==maximum)
            count_max++;
    }

    return count_max;
}

int main()
{
    int n,m,i,a,b,t;
    unsigned long long int total=1llu;

    cin>>n>>m;
    if(m==0)
    {
        cout<<"1\n";
        return 0;
    }

    vector <int> g[n+1];
    int knowledge[n+1],visited[n+1];

    for(i=1;i<=n;i++)
    {
        cin>>knowledge[i];
        visited[i]=0;
    }

    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            t=dfs_modify(g,knowledge,visited,i);
            total=(((unsigned long long int)t%MOD)*(total%MOD))%MOD;
        }
    }
    cout<<total<<endl;
    return 0;
}
