#include <bits/stdc++.h>

using namespace std;

int max_ammunations(vector< pair<int,int> >am, int n, int w)
{
    if(n==0)
        return 0;
    sort(am.begin(),am.end());
    int i,j,max_am[n][w+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0)
            {
                if(am[i].first<=j)
                    max_am[i][j]=am[0].second;
                else
                    max_am[i][j]=0;
            }
            else if(am[i].first>j)
                max_am[i][j]=max_am[i-1][j];
            else
                max_am[i][j]=max(max_am[i-1][j-am[i].first]+am[i].second,max_am[i-1][j]);
        }
    }
    return max_am[n-1][w];
}

int main()
{
    int t,n,w,i,wt[10001],amm[10001];
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        for(i=0;i<n;i++)
            cin>>wt[i];
        for(i=0;i<n;i++)
            cin>>amm[i];
        vector< pair<int,int> >am;
        for(i=0;i<n;i++)
            am.push_back(make_pair(wt[i],amm[i]));
        cout<<max_ammunations(am,n,w)<<endl;
    }
    return 0;
}

