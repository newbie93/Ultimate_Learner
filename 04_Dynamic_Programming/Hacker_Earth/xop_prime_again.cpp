#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool test[10000 + 5];

int dp[10000 + 5];

vector<int>v;

int MAX=1e9;

void seive()
{
 for (int i = 2; i < 1e4; i++)
 {
  if (!test[i])
  {
   v.push_back(i);
   for (int j = i*i; j < 1e4; j += i)test[j] = 1;
  }
 }
}


void pre()
{
 seive();
    v.push_back(4);
    v.push_back(27);
    v.push_back(3125);
 fill(dp, dp + 10001, MAX-1);
 dp[0] = 0;
 sort(v.begin(),v.end());
 for (int i = 2; i <=1e4; i++)
 {
  for (int j = 0; j < v.size() && v[j]<=i; j++)
  {
    dp[i] = min(dp[i], dp[i - v[j]] + 1);

  }
 }
}

int main()
{
 //ios_base::sync_with_stdio(0);
 int t;
 scanf("%d", &t);
 pre();
 while (t--)
 {
  int n;
  scanf("%d", &n);
  printf("%d\n", dp[n]);
 }

 return 0;
}
