
//quy hoach dong doi tien
#include<bits/stdc++.h>
using namespace std;
class money
{
	int n,a[100],C[100][100]={},M;
	void dp() //dynamic programming
	{
		for(int j=1;j<=M;j++) C[0][j]=1e9;  //inf=1e9
		for(int i=1;i<=n;i++)
		for(int j=1;j<=M;j++)
		if(a[i]>j) C[i][j]=C[i-1][j];
		else C[i][j]=min(C[i-1][j],1+C[i][j-a[i]]);
	}
	string trace(int n,int M)
	{
		if(C[n][M]==0) return "";
		while(C[n][M]==C[n-1][M]) n--;
		return trace(n,M-a[n])+"+"+to_string(a[n]);
	}
	public: void sol()
	{
		cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
		cin>>M;
		dp();
		if(C[n][M]==1e9) cout<<"\nKhong doi duoc";
		else 
		{
			cout<<"\nSo to it nhat "<<C[n][M]<<"\n";
			string tmp=trace(n,M);
			cout<<tmp.substr(1);
		}
	}
};
int main(){	money M; M.sol();}


