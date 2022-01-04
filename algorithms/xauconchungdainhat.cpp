#include<bits/stdc++.h>
using namespace std;
class xcc
{
	string x,y;
	int n,m,c[100][100]={};
	void dp()  //dynamic programming
	{
		for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++) 
		c[i][j]=x[i]==y[j]?c[i-1][j-1]+1:max(c[i-1][j],c[i][j-1]);
	}
	void trace(int u,int v)
	{
		if(c[u][v]==0) return ;
		while(c[u][v]==c[u][v-1]) v--;
		while(c[u][v]==c[u-1][v]) u--;
		trace(u-1,v-1) ; cout<<x[u];
	}
	public:void sol()
	{
		cin>>x>>y; n=x.size();m=y.size();
		x="$"+x; y="$"+y;
		dp();
		cout<<"\nChung dai nhat "<<c[n][m]<<" ky tu : ";
		trace(n,m);
	}
};
int main()
{
	xcc Z;Z.sol();
}


