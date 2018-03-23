#include<bits/stdc++.h>
#include<climits>

#define VERTEX first
#define CAPACITY second

using namespace std;

int max_cap[101][101],mark[101];


int minimum(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int get_max_cap(vector< pair<int,int> >g[],int s,int d)
{
	if((s==d)&&(s==d))
    {
        return INT_MAX;
	}
	mark[s]=1;

	int vertex,capacity,new_capacity,max_capacity=-1;

	for(int i=0;i<g[s].size();i++)
	{
	    vertex=g[s][i].VERTEX;
	    capacity=g[s][i].CAPACITY;

        if(mark[vertex]==0)
        {
            new_capacity=minimum(capacity,get_max_cap(g,vertex,d));
            if(max_capacity<new_capacity)
                max_capacity=new_capacity;
        }
	}

	mark[s] = 0;
	return max_capacity;
}

int main()
{
	int n,m,s,d,num,i,a,b,c;
	cin >> n >> m;
	vector < pair<int,int> >g[n+1];
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    cin>>s>>d>>num;

    cout<<ceil((num+1)/(double)(get_max_cap(g,s,d)-1))<<endl;
	return 0;
}

