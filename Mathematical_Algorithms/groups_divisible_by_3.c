
#include <stdio.h>


int main() {
    int t,n,k,i;
    int arr[3];
    unsigned long long int ans=0llu;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        arr[0]=arr[1]=arr[2]=0;
        ans=0llu;
        while(n--)
        {
            scanf("%d",&k);
            arr[(k%3)]++;
        }
        ans+=((unsigned long long int)arr[0]*(unsigned long long int)(arr[0]-1))/2llu;
        ans+=(unsigned long long int)arr[1]*(unsigned long long int)arr[2];
        ans+=((unsigned long long int)arr[0]*(unsigned long long int)(arr[0]-1)*(unsigned long long int)(arr[0]-2))/6llu;
        ans+=((unsigned long long int)arr[1]*(unsigned long long int)(arr[1]-1)*(unsigned long long int)(arr[1]-2))/6llu;
        ans+=((unsigned long long int)arr[2]*(unsigned long long int)(arr[2]-1)*(unsigned long long int)(arr[2]-2))/6llu;
        ans+=(unsigned long long int)arr[0]*(unsigned long long int)arr[1]*(unsigned long long int)arr[2];
        printf("%llu\n",ans);
    }
	return 0;
}
