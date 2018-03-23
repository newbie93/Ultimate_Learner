#include<bits/stdc++.h>


using namespace std;


void bubble_sort(int*a,int*qu,int q)
{
    int i,j,temp,chk=1;
    for(i=1;i<q && chk==1;i++)
    {
        chk=0;
        for(j=1;j<=q-i;j++)
        {
            if(a[qu[j+1]]>a[qu[j]])
            {
                temp=qu[j];
                qu[j]=qu[j+1];
                qu[j+1]=temp;
                chk=1;
            }
        }
    }
}

int main()
{
    int n,t,q,u,a[101],qu[501],c[101],index,change,i,k;

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    cin>>t;
    while(t--)
    {
        cin>>q>>u;

        for(i=1;i<=q;i++)
            cin>>qu[i];

        for(i=1;i<=u;i++)
        {
            cin>>index>>change;
            a[index]=change;
        }

        bubble_sort(a,qu,q);

        for(i=1;i<=n;i++)
            c[i]=0;

        for(i=1;i<=q;i++)
        {
            if(c[qu[i]]==0)
            {
                cout<<qu[i]<<" ";
                c[qu[i]]=1;
            }
        }


    }
    return 0;
}
