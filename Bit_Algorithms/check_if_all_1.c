#include <stdio.h>

int main() {
    int t,n,k=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        while(n>0)
        {
            if((n&1)!=1)
                break;
            n=(n>>1);
        }
        if(n<=0)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
