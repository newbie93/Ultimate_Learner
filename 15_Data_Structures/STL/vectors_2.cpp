#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> g;
    vector <int> :: iterator iter;

    int n=5;

    for(int i=1;i<=n;i++)
        g.push_back(i);

    cout<<"using [] :\n";
    for(int i=0;i<n;i++)
        cout<<g[i]<<endl;

    cout<<"using at() :\n";
    for(int i=0;i<n;i++)
        cout<<g.at(i)<<endl;

    cout<<"using iterator :\n";
    for(iter=g.begin();iter!=g.end();iter++)
        cout<<*iter<<endl;

    cout<<"element at front: "<<g.front()<<endl;
    cout<<"element at back: "<<g.back()<<endl;

    return 0;
}
