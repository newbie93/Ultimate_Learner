#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> first;
    vector <int> :: iterator iter;
    vector <int> :: reverse_iterator rev_iter;

    int i;
    for(i=1;i<=100;i++)
        first.push_back(i);

    cout<<"normal order\n";
    for(iter=first.begin();iter!=first.end();++iter)
        cout<<*iter<<endl;

    cout<<"reverse\n";
    for(rev_iter=first.rbegin();rev_iter!=first.rend();++rev_iter)
        cout<<*rev_iter<<endl;

    cout<<"capacity :- "<<first.capacity()<<endl;
    cout<<"size :- "<<first.size()<<endl;
    cout<<"max size :- "<<first.max_size()<<endl;
    first.resize(1000);
    cout<<"size :- "<<first.size()<<endl;

    return 0;
}
