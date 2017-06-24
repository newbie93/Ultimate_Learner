#include <bits/stdc++.h>

using namespace std;

int path[10001][10001];

int visited[10001];

vector <int> st;

void mark_children(vector <int> g[], int s, int ptr)
{
    int i;
    visited[s]=1;
    for(i=0;i<g[s].size();i++)
    {
        if(visited[g[s][i]]==0)
        {
            st.push_back(g[s][i]);
            mark_children(g,g[s][i],ptr+1);
        }
    }
    for(i=ptr;i<st.size();i++)
        path[s][st[i]]=1;
}

int main()
{

    int n,a,b,c,q,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        for(j=1;j<=n;j++)
            path[i][j]=0;
    }
    vector <int>g[n+1];
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            mark_children(g,i,0);
            if(!st.empty())
                st.clear();
        }
    }

    cin>>q;

    for(i=1;i<=q;i++)
    {
        cin>>a>>b>>c;
        if(a==0)
        {
            if(path[b][c]==1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else
        {
            if(path[c][b]==1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
