#include <stdio.h>

int plant[1001][2];

int table[1001][10001];

void heapify(int i, int n)
{
    if(i*2>n)
        return;
    int largest=i,temp_1,temp2;
    if(plant[i*2][0]>plant[largest][0])
        largest=i*2;
    if(i*2+1<=n && plant[i*2+1][0]>plant[largest][0])
        largest=i*2+1;
    if(largest!=i)
    {
        temp_1=plant[i][0];
        temp_2=plant[i][1];
        plant[i][0]=plant[largest][0];
        plant[i][1]=plant[largest][1];
        plant[largest][0]=temp_1;
        plant[largest][1]=temp_2;
        heapify(largest);
    }
}

void make_heap(int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        heapify(i);
}

void heap_sort(int n)
{
    make_heap();
    int i,temp_1,temp_2;
    for(i=1;i<n;i++)
    {
        temp_1=plant[1][0];
        temp_2=plant[1][1];
        plant[1][0]=plant[n-i+1][0];
        plant[1][1]=plant[n-i+1][1];
        plant[n-i+1][0]=temp_1;
        plant[n-i+1][1]=temp_2;
        heapify(1,n-i);
    }
}

int min_fertilizer(int n, int p)
{
    int  i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=p;j++)
        {
            if(i==0 || j==0)
                table[i][j]=0;
            else if(plant[i][0]<=j)
                table[i][j]=max(table[i-1][j-plant[i][0]]+1,table[i-1][j]);
            else
                table[i][j]=table[i-1][j];
        }
    }

}

int main()
{
    printf("Hello World!\n");
    return 0;
}
