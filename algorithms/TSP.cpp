//SINH HOAN VI
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100][100],x[100],res=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cin>>a[i][j];
		x[i]=i;
	}
	x[n+1]=1;
	do
	{
		int t=0;
		for(int i=1;i<=n;i++) t+=a[x[i]][x[i+1]];
		res=min(res,t);
	}while(next_permutation(x+2,x+n+1));
	cout<<res;
}


