#include <bits/stdc++.h>

#define MOD 1000000009
#define ull unsigned long long int

using namespace std;


bool sortbysec(const pair<ull,ull> &a, const pair<ull,ull> &b)
{
    return (a.first > b.first);
}

int main()
{
    int t,n,i;
    ull sum,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector < pair <ull,ull> >g;
        for(i=0;i<n;i++)
        {
            cin>>a;
            g.push_back(make_pair(a,0llu));
        }
        sort(g.begin(),g.end(),sortbysec);
        sum=0llu;
        for(i=n-2;i>=0;i--)
        {
            g[i].second=(((g[i].first-g[i+1].first)*(n-1-i))%MOD + g[i+1].second)%MOD;
            sum=(sum+g[i].second)%MOD;
        }
        //cout<<sum<<endl;
        sum=(sum*g[0].first)%MOD;
        cout<<sum<<endl;
    }
    return 0;
}

