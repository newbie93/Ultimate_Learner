#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    priority_queue < int , vector <int> , greater <int> > q;
    q.push(100);
    q.push(90);
    q.push(80);
    q.push(70);
    q.push(60);
    q.push(50);
    q.push(40);
    q.push(30);
    q.push(20);
    q.push(10);
    q.push(1);
    q.push(100);
    q.push(90);
    q.push(80);
    q.push(70);
    q.push(60);
    q.push(50);
    q.push(40);
    q.push(30);
    q.push(20);
    q.push(10);
    q.push(1);
    while(!q.empty())
    {
        k=q.top();
        q.pop();
        cout<<k<<" ";
    }
    return 0;
}
