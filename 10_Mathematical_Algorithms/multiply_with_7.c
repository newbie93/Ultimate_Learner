#include<stdio.h>

int mul_7(int n)
{
    return (n<<2)+(n<<1)+n;
}

int main()
{
    printf("%d\n",mul_7(2));
    return 0;
}
