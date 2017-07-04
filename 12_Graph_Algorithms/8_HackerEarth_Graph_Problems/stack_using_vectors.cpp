
#include<bits/stdc++.h>

using namespace std;

class Stack
{
    public:
        void push(int data);
        int pop();

    private:
       vector <int>stck;
};



int Stack :: pop()
{
    if(stck.empty())
        return -1001;
    int data=stck.back();
    stck.pop_back();
    return data;
}

void Stack :: push(int data)
{
     stck.push_back(data);
}

int main()
{
    Stack s;
    for(int i=1;i<=10;i++)
        s.push(i);
    for(int i=1;i<=10;i++)
        cout<<s.pop()<<" ";
    cout<<endl;
    return 0;
}
