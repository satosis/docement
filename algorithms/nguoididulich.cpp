#include<bits/stdc++.h>
using namespace std;
class TPS
{
	int n,a[100][100],res=INT_MAX,d[100]={},cmin=1e9;
	public: void sol()
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {cin>>a[i][j]; if(cmin>a[i][j]) cmin=a[i][j];}
		d[1]=1;
		TRY(2,1,0);
		cout<<res;
	}
	void TRY(int k,int x,int t)  //gia su da co x1...x[k-1] phan tu cuoi x, 
	{
		if(k>n)
		{
			res=min(res,t+a[x][1]);
			return;
			
		}
		for(int z=2;z<=n;z++)
		if(d[z]==0)
		{
			d[z]=1;
			if(t+a[x][z] +cmin*(n-k+1) <res) TRY(k+1,z,t+a[x][z]);
			d[z]=0;
		}
	}
};
int main(){	TPS T; T.sol();}


