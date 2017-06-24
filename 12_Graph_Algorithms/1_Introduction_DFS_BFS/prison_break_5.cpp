#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int cell[21][21],mark[21][21],count_route=0,n;

void route(int i,int j){
	if((i==n)&&(j==n)){
		count_route++;
		return;
	}
	mark[i][j] = 1;
	if( (j+1)<=n && mark[i][j+1] == 0 && cell[i][j+1] == 0 )
		route(i,j+1);
	if( (i+1)<=n && mark[i+1][j] == 0 && cell[i+1][j] == 0 )
		route(i+1,j);
	if( (j-1)>=1 && mark[i][j-1] == 0 && cell[i][j-1] == 0 )
		route(i,j-1);
	if( (i-1)>=1 && mark[i-1][j] == 0 && cell[i-1][j] == 0 )
		route(i-1,j);
	mark[i][j] = 0;
	return;
}

int main()
{
	int i,j,t;
	cin >> t;
	while(t--){
		cin >> n;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cin >> cell[i][j];
				mark[i][j] = 0;
			}
		}
		count_route = 0;
		route(1,1);
		cout << count_route << endl;
	}
	return 0;
}
