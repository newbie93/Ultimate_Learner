#include<bits/stdc++.h>

#define ll long long int

using namespace std;

bool comp(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return ((a.first+a.second) > (b.first+b.second));
}

int main()
{
    int t,n,i,cost;
    ll a,b,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector < pair<ll,ll> >g;
        sum=0ll;
        for(i=0;i<n;i++)
        {
            cin>>a>>b;
            g.push_back(make_pair(a,b));
            sum=sum+b;
        }
        sort(g.begin(),g.end(),comp);
        sum=0ll-(sum-(g[0].first+g[0].second+g[1].first+g[1].second));
        cout<<sum<<endl;
    }
    return 0;
}
