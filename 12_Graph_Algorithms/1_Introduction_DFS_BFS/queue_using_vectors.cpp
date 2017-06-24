#include<bits/stdc++.h>

using namespace std;

class Queue
{
    public:
        void enqueue(int data);
        int dequeue();

    private:
        vector <int> que;
};

int Queue :: dequeue()
{
     if(que.empty())
         return -1001;
     int data=que.back();
     que.pop_back();
     return data;
}

void Queue :: enqueue(int data)
{
     que.insert(que.begin(),data);
}

int main()
{
    Queue q;
    for(int i=1;i<=10;i++)
        q.enqueue(i);
    for(int i=1;i<=10;i++)
        cout<<q.dequeue()<<" ";
    cout<<endl;
    return 0;
}
