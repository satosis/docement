#include<bits/stdc++.h>
using namespace std;
#define MAX 106
long long n,a[MAX][MAX]={},c[MAX][MAX]={},res=-LLONG_MAX;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=n;j++) cin>>a[i][j];
	
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=n;j++) c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+a[i][j];
	
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=n;j++)
	{
		long long z=c[i][j];
		for(int u=1;u<=i;u++)
		for(int v=1;v<=j;v++)
		{
			int k=c[i][j]-c[u][j]-c[i][v]+c[u][v];
			if(z<k) z=k;
		}
		if(res<z) res=z;
	}
	cout<<res;
}


