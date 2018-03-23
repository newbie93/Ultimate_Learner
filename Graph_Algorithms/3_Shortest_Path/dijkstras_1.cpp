#include<bits/stdc++.h>

#define MAX_EDGES 1000001
#define MAX_VERTEX 100001

#define VERTEX first
#define COST second

using namespace std;

typedef struct Edge{ int vertex,cost;} Edge;

Edge edge_list[MAX_EDGES];
int vertex_ptr[MAX_VERTEX];
int edge_num=0;


int is_present(int vertex)
{
    if(vertex_ptr[vertex]>0)
        return 1;
    return 0;
}

int edge_list_empty()
{
    if(edge_num<1)
        return 1;
    return 0;
}

void make_edge_list_empty()
{
    edge_num=0;
}

int get_cost(int vertex)
{
    if(vertex_ptr[vertex]>0)
        return edge_list[vertex_ptr[vertex]].cost;
    return -1001;
}

void insert_edge(int vertex,int cost)
{
    edge_num++;
    int i;
    for(i=edge_num;i>1;i/=2)
    {
        if(edge_list[i/2].cost<cost)
            break;
        edge_list[i].vertex=edge_list[i/2].vertex;
        edge_list[i].cost=edge_list[i/2].cost;
        vertex_ptr[edge_list[i].vertex]=i;
    }
    edge_list[i].vertex=vertex;
    edge_list[i].cost=cost;
    vertex_ptr[edge_list[i].vertex]=i;
}

void update_edge(int vertex,int new_cost)
{
    if(is_present(vertex)==0)
        return;
    int old_cost=get_cost(vertex);
    if(old_cost<=new_cost)
        return;
    int i,ptr=vertex_ptr[vertex];
    for(i=ptr;i>1;i/=2)
    {
        if(edge_list[i/2].cost<new_cost)
            break;
        edge_list[i].vertex=edge_list[i/2].vertex;
        edge_list[i].cost=edge_list[i/2].cost;
        vertex_ptr[edge_list[i].vertex]=i;
    }
    edge_list[i].vertex=vertex;
    edge_list[i].cost=new_cost;
    vertex_ptr[edge_list[i].vertex]=i;
}

void heapify(int i)
{
    if(i*2>edge_num)
        return;

    int minimum=i,temp_cost,temp_vertex;

    if(edge_list[i*2].cost<edge_list[minimum].cost)
        minimum=i*2;

    if(i*2+1<=edge_num && edge_list[i*2+1].cost<edge_list[minimum].cost)
        minimum=i*2+1;

    if(i!=minimum)
    {
        vertex_ptr[edge_list[minimum].vertex]=i;
        vertex_ptr[edge_list[i].vertex]=minimum;

        temp_vertex=edge_list[i].vertex;
        temp_cost=edge_list[i].cost;

        edge_list[i].vertex=edge_list[minimum].vertex;
        edge_list[i].cost=edge_list[minimum].cost;

        edge_list[minimum].vertex=temp_vertex;
        edge_list[minimum].cost=temp_cost;

        heapify(minimum);

    }
}

Edge* rem_min()
{
    if(edge_num<0)
        return NULL;

    Edge*edge=(Edge*)malloc(sizeof(Edge));
    edge->cost=edge_list[1].cost;
    edge->vertex=edge_list[1].vertex;

    edge_list[1].cost=edge_list[edge_num].cost;
    edge_list[1].vertex=edge_list[edge_num].vertex;

    vertex_ptr[edge_list[1].vertex]=1;

    vertex_ptr[edge->vertex]=0;

    edge_num--;
    heapify(1);
    return edge;
}


void dijkstra(vector< pair<int,int> >g[],int final_cost[],int s,int n)
{
    Edge*edge;
    int i,cost,vertex,visited[n+1],con_vertex,con_cost;
    for(i=1;i<=n;i++)
    {
        visited[i]=vertex_ptr[i]=0;
        final_cost[i]=INT_MAX;
    }

    insert_edge(s,0);

    while(edge_list_empty()==0)
    {
        edge=rem_min();
        vertex=edge->vertex;
        cost=edge->cost;
        final_cost[vertex]=cost;

        visited[vertex]=1;

        for(i=0;i<g[vertex].size();i++)
        {

            con_vertex=g[vertex][i].VERTEX;
            con_cost=g[vertex][i].COST+cost;

            if(visited[con_vertex]==0)
            {
                if(is_present(con_vertex)==0)
                    insert_edge(con_vertex,con_cost);
                else if(is_present(con_vertex)==1 && con_cost<get_cost(con_vertex))
                    update_edge(con_vertex,con_cost);
            }

        }

    }

}

int main()
{
    int n,m,i,a,b,c;
    cin>>n>>m;
    int cost[n+1];
    vector< pair<int,int> >g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }
    dijkstra(g,cost,1,n);
    for(i=2;i<=n;i++)
        cout<<cost[i]<<" ";
    cout<<endl;
    return 0;
}
