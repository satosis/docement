#include<bits/stdc++.h>
using namespace std;
#define w second
#define v first
class balo
{
	int n,M,res=0,T[105]={};
	pair<int,int> A[105];
	void nhap()
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>A[i].w>>A[i].v;
		sort(A+1,A+n+1,greater<pair<int,int>>());
		for(int i=n;i>=1;i--) T[i]=T[i+1]+A[i].v;
	}
	void TRY(int k,int W,int V) //x1...xk nhan gia tri 0 hoac 1
	{
		if(k==n) res=max(res,V);
		else
		{
			if(W+A[k+1].w<=M && res<V+A[k+1].v+T[k+2]) TRY(k+1,W+A[k+1].w,V+A[k+1].v);
			TRY(k+1,W,V);
		}
	}
	public:void sol()
	{
		nhap();
		int t;
		cin>>t;
		while(t--)
		{
			cin>>M; res=0;
			TRY(0,0,0);
			cout<<res<<"\n";
		}
	}
};
int main()
{
	balo B; B.sol();
}


