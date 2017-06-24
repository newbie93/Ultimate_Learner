#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={10,2,6,8,3,5,7,4,1,9};
    sort(a,a+10);
    vector <int> v(a,a+10);
    vector <int> v1,v2;
    vector <int> :: iterator i,j;

    cout<<"v : \n";
    for(i=v.begin();i!=v.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    i=v.begin()+2;
    j=v.end()-2;
    v1.assign(i,j);

    cout<<"v1 : \n";
    for(i=v1.begin();i!=v1.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    v2.assign(10,5);
    cout<<"v2 : \n";
    for(i=v2.begin();i!=v2.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    return 0;
}
