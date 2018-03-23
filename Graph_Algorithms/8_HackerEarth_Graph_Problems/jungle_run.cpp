#include <bits/stdc++.h>

#define X first
#define Y second
#define MAX 40

using namespace std;

int bfs(int **a,int **visited,int n,int i,int j)
{
    int level=0,reached=0;

    queue < pair <int,int> > q;
    q.push(make_pair(i,j));
    q.push(make_pair(0,0));
    visited[i][j]=1;

    while(!q.empty())
    {
        i=q.front().X;
        j=q.front().Y;

        q.pop();

        if(i==0)
        {
            level++;
            if(q.empty())
                break;
            q.push(make_pair(0,0));
        }
        else
        {
            if(a[i][j]=='E')
            {
                reached=1;
                break;
            }

            if(i>1 && visited[i-1][j]==0 && a[i-1][j]!='T')
            {
                q.push(make_pair(i-1,j));
                visited[i-1][j]=1;
            }

            if(i<n && visited[i+1][j]==0 && a[i+1][j]!='T')
            {
                q.push(make_pair(i+1,j));
                visited[i+1][j]=1;
            }

            if(j>1 && visited[i][j-1]==0 && a[i][j-1]!='T')
            {
                q.push(make_pair(i,j-1));
                visited[i][j-1]=1;
            }

            if(j<n && visited[i][j+1]==0 && a[i][j+1]!='T')
            {
                q.push(make_pair(i,j+1));
                visited[i][j+1]=1;
            }
        }
    }
    if(reached==1)
        return level;
    return 0;
}

int main()
{
    int n,i,j,x,y;
    char c;
    cin>>n;
    int **a,**visited;
    a=(int**)malloc(sizeof(int*)*(n+1));
    visited=(int**)malloc(sizeof(int*)*(n+1));
    for(i=1;i<=n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*(n+1));
        visited[i]=(int*)malloc(sizeof(int)*(n+1));
        for(j=1;j<=n;j++)
        {
            visited[i][j]=0;
            c=cin.get();
            c=cin.get();
            a[i][j]=c;
            if(a[i][j]=='S')
            {
                x=i;
                y=j;
            }
        }
    }
    cout<<bfs(a,visited,n,x,y)<<endl;
    return 0;
}

