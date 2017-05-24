/*
        greedy_knap_sack.c

        here we have implemented the greedy knap-sack problem.
        given a collection of objects, associated profits
        and weights, and a weight bearing capacity of a knap-
        sack, we have to find out, what is the maximum profit
        can be achieved by stealing some/all of the objects from
        the collection, keeping in mind the capacity of the knapsack.
        Objects can be taken partially.
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int partition(double**a,int lb,int ub)
{
    int i=lb-1,j=lb;
    double temp,temp1,temp2,pivot_num=a[ub][0],pivot_denom=a[ub][1],pivot=pivot_num/pivot_denom;
    while(j<ub)
    {
        temp=a[j][0]/a[j][1];
        if(temp>=pivot)
        {
            i++;
            temp1=a[i][0];
            temp2=a[i][1];
            a[i][0]=a[j][0];
            a[i][1]-a[j][1];
            a[j][0]=temp1;
            a[j][1]=temp2;
        }
        j++;
    }
    i++;
    a[ub][0]=a[i][0];
    a[ub][1]=a[i][1];
    a[i][0]=pivot_num;
    a[i][1]=pivot_denom;
    return i;
}

void quick_sort(double**a,int lb,int ub)
{
    if(lb>=ub)
        return;
    int j=partition(a,lb,ub);
    quick_sort(a,lb,j-1);
    quick_sort(a,j+1,ub);
}

double max_profit(double*profit,double*wt,int n,double capacity)
{
    int i,ptr=0;
    double **temp=(double**)malloc(sizeof(double*)*n),max_profit=0.0;
    for(i=0;i<n;i++)
    {
        temp[i]=(double*)malloc(sizeof(double)*2);
        temp[i][0]=profit[i];
        temp[i][1]=wt[i];
    }
    quick_sort(temp,0,n-1);
    for(i=0;i<n;i++)
        printf("%lf %lf -> %lf\n",temp[i][0],temp[i][1],(temp[i][0]/temp[i][1]));
    while(capacity>0.0 && ptr<n)
    {
        if(temp[ptr][1]>=capacity)
        {
            max_profit+=(temp[ptr][0]/temp[ptr][1])*capacity;
            capacity=0.0;
        }
        else
        {
            max_profit+=temp[ptr][0];
            capacity-=temp[ptr][1];
        }
        ptr++;
    }
    return max_profit;
}

int main()
{
    double profit[]={10.0,20.0,30.0,40.0},wt[]={1.0,4.0,7.0,2.0},capacity=6.0;
    int n=4;
    printf("%lf\n",max_profit(profit,wt,n,capacity));
    return 0;
}
