

#include<stdio.h>
int main()
{
    int i;
    unsigned long long int s=1;
    for(i=0;i<28;i++)
    {
        printf("%llu\n",s),s=(s<<1);
    }
    return 0;
}
