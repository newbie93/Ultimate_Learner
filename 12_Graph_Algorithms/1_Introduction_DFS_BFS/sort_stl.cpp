#include<bits/stdc++.h>

using namespace std;

typedef pair < int , int > P;

int main()
{
    vector < pair < P , int > > v;
    v.push_back(make_pair(make_pair(100,1),2));
    v.push_back(make_pair(make_pair(90,2),0));
    v.push_back(make_pair(make_pair(80,-1),3));
    v.push_back(make_pair(make_pair(70,0),4));
    sort( v.begin() , v.end() , greater < pair < P , int > > () );
    for(int i=0;i<v.size();i++)
        cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
    return 0;
}
