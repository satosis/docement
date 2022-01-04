//hinh vuong lon nhat
#include<bits/stdc++.h>
using namespace std;
#define MAX 106
int n,m,a[MAX][MAX],c[MAX][MAX],res=0;
int fun(int b)
{
	int res=0;
	for(int i=1;i<=n;i++) c[i][1]=a[i][1]==b?1:0; 
	for(int j=1;j<=m;j++) c[1][j]=a[1][j]==b?1:0; 
	for(int i=2;i<=n;i++) 
	for(int j=2;j<=m;j++)
	{
		if(a[i][j]!=b) c[i][j]=0;
		else 
		{
			if(a[i-1][j]==b && a[i][j-1] == b) 
			{
				int k=min(c[i-1][j],c[i][j-1]);
				c[i][j] = k + (a[i-k][j-k]==b);
			}
			else c[i][j]=1;
		}
		if(res<c[i][j]) res=c[i][j];
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) cin>>a[i][j];
	cout<<max(fun(1),fun(1));
}


