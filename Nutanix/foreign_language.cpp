#include<bits/stdc++.h>

#define MAX 1000000009

using namespace std;

vector<int>g[26];
int in_degree[26];
stack<int>s;
int visited[26];

pair<int,int> get_order(string str1, string str2)
{
    int i=0,j=0,len1=str1.length(),len2=str2.length();
    for(;i<len1 && j<len2;i++,j++)
    {
        if(str1[i]!=str2[j])
            return make_pair(str1[i]-'a',str2[j]-'a');
    }
    return make_pair(-1,-1);
}

void order(string arr[], int n)
{
    int i,j,k,l;
    pair<int,int>p;
    for(i=0;i<26;i++)
        visited[i]=0,in_degree[i]=MAX;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            p=get_order(arr[i],arr[j]);
            k=p.first;
            l=p.second;
            if(k==-1)
                continue;
            g[k].push_back(l);
            if(in_degree[k]==MAX)
                in_degree[k]=0;
            if(in_degree[l]==MAX)
                in_degree[l]=0;
            in_degree[l]++;
        }
    }
}

void conquer_deapth(int i)
{
    visited[i]=1;
    for(int j=0;j<g[i].size();j++)
    {
        if(visited[g[i][j]]==0)
            conquer_deapth(g[i][j]);
    }
    s.push(i);
}


void topo_sort(string arr[], int n)
{
    int i;
    order(arr, n);
    for(i=0;i<26;i++)
    {
        if(in_degree[i]==0)
            conquer_deapth(i);
    }
}

int main()
{
    int i,n;
    cin>>n;
    string arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    topo_sort(arr, n);
    while(!s.empty())
    {
        cout<<(char)(s.top()+'a')<<" ";
        s.pop();
    }
    return 0;
}
