#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,index,temp,t,n,k,a[10001];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector < pair<int,int> > g;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            g.push_back(make_pair(temp,i));
        }
        sort(g.begin(),g.end());
        for(i=0;i<k;i++)
            cin>>a[i];
        sort(a+1,a+k+1);
        index=1000000009;
        for(i=k-1,j=n-1;i>=0 && j>=0;)
        {
            if(g[j].first>=a[i])
            {
                if(g[j].second<index)
                    index=j;
                j--;
            }
            else
                i--;
        }
        if(index==1000000009)
            cout<<"0\n";
        else
            cout<<index<<endl;
    }
    return 0;
}
