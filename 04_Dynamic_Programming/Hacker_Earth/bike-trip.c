#include<stdio.h>

#define ull unsigned long long int

int path[100005][2];
int cost_change[100005][2];

ull cost[100005][2];

ull minimum(ull a,ull b)
{
    if(a<b)
        return a;
    return b;
}

ull min_cost(int n,int path_no)
{
    if(n==0)
        return (ull)path[0][path_no];

    if(cost[n][path_no]>0llu)
        return cost[n][path_no];

    ull a,b;

    a=min_cost(n-1,path_no);//+path[n][path_no];
    b=min_cost(n-1,!path_no)+(ull)cost_change[n-1][!path_no];//+path[n][path_no];

    a=minimum(a,b);

    return (cost[n][path_no]=a+(ull)path[n][path_no]);

}


int main()
{
    int t,n,i;
    //ull a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            cost[i][0]=cost[i][1]=0llu;

        for(i=0;i<n;i++)
            scanf("%d",&path[i][0]);
        for(i=0;i<n;i++)
            scanf("%d",&path[i][1]);
        for(i=0;i<n-1;i++)
            scanf("%d",&cost_change[i][0]);
        for(i=0;i<n-1;i++)
            scanf("%d",&cost_change[i][1]);

        if(n==1)
        {
            printf("%llu\n",minimum((ull)path[0][0],(ull)path[0][1]));
            continue;
        }

        printf("%llu\n",minimum(min_cost(n-1,0),min_cost(n-1,1)));

    }
    return 0;
}
