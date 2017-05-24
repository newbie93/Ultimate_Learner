#include<stdio.h>
#include<assert.h>

unsigned long long int temp[100];

unsigned long long int find_fibo_term(int n)
{
    assert(n<=93);
    temp[0]=0ll;
    temp[1]=1ll;
    int i;
    for(i=2;i<=n;i++)
        temp[i]=temp[i-1]+temp[i-2];
    return temp[n];
}

int main()
{
    int n=56;
    printf("The %d fibonacci term is %llu\n",n,find_fibo_term(n));
    return 0;
}
