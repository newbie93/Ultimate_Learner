#include<bits/stdc++.h>

#define NODE_NOT_PRESENT 0
#define NODE_PRESENT_NOT_VISITED 1
#define NODE_PRESENT_AND_VISITED 2

#define MAX_VERTEX 200001

using namespace std;

void connected_comp_mod(vector <int>g[],int visited[],int n,int s,int x)
{
    int i;
    stack <int>st;
    st.push(s);
    visited[s]=NODE_PRESENT_AND_VISITED;
    if(s==x)
        return;
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        for(i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==NODE_PRESENT_NOT_VISITED && g[s][i]!=x)
            {
                st.push(g[s][i]);
                visited[g[s][i]]=NODE_PRESENT_AND_VISITED;
            }
        }
    }
}

int main()
{
    int n,k,x,a,b,i,visited[MAX_VERTEX];
    vector <int> g[MAX_VERTEX];
    cin>>n>>k;
    for(i=0;i<=MAX_VERTEX;i++)
        visited[i]=NODE_NOT_PRESENT;
    for(i=1;i<=k;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        visited[a]=visited[b]=NODE_PRESENT_NOT_VISITED;
    }
    cin>>x;
    connected_comp_mod(g,visited,n,a,x);
    for(i=0;i<=MAX_VERTEX;i++)
    {
        if(visited[i]==NODE_PRESENT_NOT_VISITED)
            break;
    }
    if(i>MAX_VERTEX)
        cout<<"Connected\n";
    else
        cout<<"Not Connected\n";
    return 0;
}
