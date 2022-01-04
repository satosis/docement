//thuat toan quay lui cho bai toan doi tien
#include<bits/stdc++.h>
using namespace std;
class money
{
	int n,a[100],M,res=INT_MAX;  //x cac to, p phuong an tot nhat
	void TRY(int k,int t,int T)//gia su da di duoc x1...x[k-1] co x1+..x[k-1]=t va a1x1+...a[k-1]x[k-1]=T
	{
		if(k==n)
		{
			if((M-T)%a[n]==0)
			{
				int x=(M-T)/a[n]; 
				if(res>t+x) res=t+x;
			}
			return;
		}
		for(int x=0;T+a[k]*x<=M && t+x<res;x++) TRY(k+1,t+x,T+a[k]*x);
	}
	public:	void sol()
	{
		cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
		cin>>M;
		TRY(1,0,0);
		if(res==INT_MAX) cout<<"\nKhong doi duoc";
		else cout<<"\nSo to it nhat "<<res<<"\n";
	}
};
int main(){money M; M.sol();}


