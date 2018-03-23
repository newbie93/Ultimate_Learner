#include<stdio.h>

#define FLAG 8388608

int find(int val[], int n)
{
    int i,k;
    for(i=0;i<n;i++)
    {
        k=val[i]&(FLAG-1);
        if(k<n)
            val[k]=val[k]|FLAG;
    }
    for(i=0;i<n;i++)
    {
        if((val[i]&FLAG)==0)
            break;
    }
    return i;
}
/*
void print_bits(int a)
{
    int i=0;
    while(i!=32)
    {
        printf("%d",(a&1));
        a=a>>1;
        i++;
    }
    printf("\n");
}
*/
int main()
{
    int n, val[100001], i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&val[i]);
    printf("%d\n",find(val,n));
    return 0;
}
