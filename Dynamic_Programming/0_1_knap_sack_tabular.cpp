#include<bits/stdc++.h>

#define MAX_ITEMS 100001
#define WEIGHT first
#define PROFIT second

using namespace std;

int max_profit(vector< pair<int,int> >items, int n, int capacity)
{
    int i,j,table[n+1][capacity+1];
    sort(items.begin(),items.end());
    for(i=0;i<=capacity;i++)
        table[0][i]=0;
    for(i=0;i<=n;i++)
        table[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=capacity;j++)
        {
            if(items.at(i-1).WEIGHT<=j)
                table[i][j]=max(table[i-1][j],items.at(i-1).PROFIT+table[i-1][j-items.at(i-1).WEIGHT]);
            else
                table[i][j]=table[i-1][j];
        }
    }
    return table[n][capacity];
}

int main()
{
    int t,i,n,capacity,a,b,t_items[200][2];
    cin>>t;
    while(t--)
    {
        cin>>n>>capacity;
        vector< pair<int,int> >items;
        for(i=0;i<n;i++)
            cin>>t_items[i][0];
        for(i=0;i<n;i++)
            cin>>t_items[i][1];
        for(i=0;i<n;i++)
            items.push_back(make_pair(t_items[i][1],t_items[i][0]));
        cout<<max_profit(items, n, capacity)<<endl;
    }
    return 0;
}
