#include<bits/stdc++.h>

#define COST first;
#define VERTEX second;

#define make_edge make_pair

using namespace std;


typedef pair <int,int> Edge;

void dijkstra(vector < Edge >g[],int final_cost[],int s,int n)
{
    int i,visited[n+1],vertex,cost,con_vertex,con_cost;
    Edge edge,found_edge;

    for(i=1;i<=n;i++)
        visited[i]=final_cost[i]=0;

    priority_queue < Edge , vector <Edge> , greater <Edge> > pq;
    pq.push(make_edge(0,s));

    while(!pq.empty())
    {
        edge=pq.top();
        pq.pop();
        vertex=edge.VERTEX;
        cost=edge.COST;
        final_cost[vertex]=cost;
        visited[vertex]=1;

        for(i=0;i<g[vertex].size();i++)
        {
            con_vertex=g[vertex][i].VERTEX;
            con_cost=g[vertex][i].COST;
            if(visited[con_vertex]==0)
            {
                /*
                        NOT POSSIBLE
                */

            }
        }

    }
}

int main()
{
    int n,m,i,a,b,c;
    cin>>n>>m;
    vector < Edge > g[n+1];
    int cost[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_edge(c,b));
    }
    return 0;
}
