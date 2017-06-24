#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 100001
#define MAX_EDGE 1000001

typedef struct Edge{int vertex,cost;} Edge;

Edge list[MAX_EDGE];
int vertex_ptr[MAX_VERTEX];
int edge_list_length=0;

void insert(int vertex,int cost)
{
    edge_list_length++;
    int i;
    for(i=edge_list_length;i>=1;i/=2)
    {
        if(list[i/2].cost<=cost)
            break;
        list[i].cost=list[i/2].cost;
        list[i].vertex=list[i/2].vertex;
        vertex_ptr[list[i].vertex]=i;
    }
    list[i].cost=cost;
    list[i].vertex=vertex;
    vertex_ptr[vertex]=i;
}

int if_vertex_present(int vertex)
{
    if(vertex_ptr[vertex]>0)
        return 1;
    return 0;
}

int update(int vertex,int new_cost)
{
    if(if_vertex_present(vertex))
    {
        int i,old_cost, ptr=vertex_ptr[vertex];
        old_cost=list[ptr].cost;
        if(new_cost>old_cost)
            return 0;
        for(i=ptr;i>=1;i/=2)
        {
            if(list[i/2].cost<=new_cost)
                break;
            list[i].cost=list[i/2].cost;
            list[i].vertex=list[i/2].vertex;
            vertex_ptr[list[i].vertex]=i;
        }
        list[i].cost=new_cost;
        list[i].vertex=vertex;
        vertex_ptr[vertex]=i;
        return 1;
    }
    return 0;
}

void heapify(int i)
{
    if(i*2>edge_list_length)
        return;
    int minimum=i,temp_vertex,temp_cost;
    if(list[i*2].cost<list[minimum].cost)
        minimum=i*2;
    if(i*2+1<=edge_list_length && list[i*2+1].cost<list[minimum].cost)
        minimum=i*2+1;
    if(i!=minimum)
    {
        temp_cost=list[i].cost;
        temp_vertex=list[i].vertex;
        list[i].cost=list[minimum].cost;
        list[i].vertex=list[minimum].vertex;
        list[minimum].cost=temp_cost;
        list[minimum].vertex=temp_vertex;
        heapify(minimum);
    }
}

Edge* get_min()
{
    if(edge_list_length<1)
        return NULL;
    Edge*edge=(Edge*)malloc(sizeof(Edge));
    edge.cost=list[1].cost;
    edge.vertex=list[1].vertex;
    list[i].cost=list[edge_list_length].cost;
    list[i].vertex=list[edge_list_length].vertex;
    edge_list_length--;
    heapify(1);
    return edge;
}

void dijkstra()

int main()
{
    return 0;
}








/*


void make_heap()
{
    int i;
    for(i=edge_list_length/2;i>=1;i--)
        heapify(i);
}
*/
