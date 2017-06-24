#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector < vector <int> > v;
    vector <int> v1;
    int a=1;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            v1.push_back(a++);
        v.push_back(v1);
        v1.clear();
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout<<v[i][j]<<"\t";
        cout<<endl;
    }

    return 0;
}
