#include<bits/stdc++.h>

#define MAX_VERTEX 100001
#define MAX_EDGE 1000001

#define VERTEX first
#define COST second

using namespace std;

typedef struct Edge{int vertex,cost;} Edge;

Edge listt[MAX_EDGE];
int vertex_ptr[MAX_VERTEX];
int edge_list_length=0;

void insertt(int vertex,int cost)
{
    edge_list_length++;
    int i;
    for(i=edge_list_length;i>1;i/=2)
    {
        if(listt[i/2].cost<cost)
            break;
        listt[i].cost=listt[i/2].cost;
        listt[i].vertex=listt[i/2].vertex;
        vertex_ptr[listt[i].vertex]=i;
    }
    listt[i].cost=cost;
    listt[i].vertex=vertex;
    vertex_ptr[vertex]=i;
}

int if_vertex_present(int vertex)
{
    if(vertex_ptr[vertex]>0)
        return 1;
    return 0;
}

int get_cost(int vertex)
{
    if(vertex_ptr[vertex]>0)
        return listt[vertex_ptr[vertex]].cost;
    return -1;
}

int update(int vertex,int new_cost)
{
    if(if_vertex_present(vertex))
    {
        int i,old_cost, ptr=vertex_ptr[vertex];
        old_cost=listt[ptr].cost;
        if(new_cost>old_cost)
            return 0;


        for(i=ptr;i>1;i/=2)
        {
            if(listt[i/2].cost<=new_cost)
                break;
            listt[i].cost=listt[i/2].cost;
            listt[i].vertex=listt[i/2].vertex;
            vertex_ptr[listt[i].vertex]=i;
        }
        listt[i].cost=new_cost;
        listt[i].vertex=vertex;
        vertex_ptr[vertex]=i;


        //cout<<"Updating vertex "<<vertex<<"at"<<ptr<<" to "<<i<<endl;

        return 1;
    }
    return 0;
}

void heapify(int i)
{
    if(i*2>edge_list_length)
        return;
    int minimum=i,temp_vertex,temp_cost;
    if(listt[i*2].cost<listt[minimum].cost)
        minimum=i*2;
    if(i*2+1<=edge_list_length && listt[i*2+1].cost<listt[minimum].cost)
        minimum=i*2+1;
    if(i!=minimum)
    {

        vertex_ptr[listt[i].vertex]=minimum;
        vertex_ptr[listt[minimum].vertex]=i;

        temp_cost=listt[i].cost;
        temp_vertex=listt[i].vertex;
        listt[i].cost=listt[minimum].cost;
        listt[i].vertex=listt[minimum].vertex;
        listt[minimum].cost=temp_cost;
        listt[minimum].vertex=temp_vertex;

        heapify(minimum);
    }
}

Edge* get_min()
{
    if(edge_list_length<1)
        return NULL;
    Edge*edge=(Edge*)malloc(sizeof(Edge));
    edge->cost=listt[1].cost;
    edge->vertex=listt[1].vertex;
    listt[1].cost=listt[edge_list_length].cost;
    listt[1].vertex=listt[edge_list_length].vertex;

    vertex_ptr[listt[1].vertex]=1;

    edge_list_length--;
    heapify(1);
    return edge;
}

int is_list_empty()
{
    if(edge_list_length<1)
        return 1;
    return 0;
}

/*void print_list()
{
    int i;
    cout<<"The queue :- "<<endl;
    for(i=1;i<=edge_list_length;i++)
        cout<<listt[i].vertex<<"  "<<listt[i].cost<<endl;
}*/

void dijkstra(vector < pair <int,int> > g[], int cost_vector[], int parent[], int n, int s)
{
    int i,vertex,cost,connected_vertex,connected_cost,visited[n+1];
    Edge*edge=NULL;
    for(i=1;i<=n;i++)
    {
        cost_vector[i]=INT_MAX;
        visited[i]=vertex_ptr[i]=parent[i]=0;
    }
    insertt(s,0);
    cost_vector[s]=0;

    //print_list();

    while(is_list_empty()==0)
    {
        edge=get_min();
        vertex=edge->vertex;
        cost=edge->cost;
        cost_vector[vertex]=cost;
        visited[vertex]=1;

        //cout<<"Vertex popped "<<vertex<<" its cost "<<cost<<endl;

        for(i=0;i<g[vertex].size();i++)
        {

            connected_vertex=g[vertex][i].VERTEX;
            connected_cost=g[vertex][i].COST + cost;

            if(visited[connected_vertex]==0)
            {
                if(vertex_ptr[connected_vertex]<1)
                {
                    insertt(connected_vertex,connected_cost);
                    parent[connected_vertex]=vertex;
                    //print_list();
                }
                else if(get_cost(connected_vertex)>connected_cost)
                {
                    //cout<<"Updated vertex "<<connected_vertex<<" from old value "<<get_cost(connected_vertex)<<" to "<<connected_cost<<endl;
                    update(connected_vertex,connected_cost);
                    parent[connected_vertex]=vertex;
                    //print_list();
                }
            }
        }

    }

}

int main()
{
    int n,m,a,b,c,i;
    cin>>n>>m;
    vector < pair<int,int> >g[n+1];
    int cost[n+1];
    int parent[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }
    dijkstra(g,cost,parent,n,1);
    for(i=2;i<=n;i++)
        cout<<cost[i]<<" ";
    cout<<endl;
    return 0;
}
