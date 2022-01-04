//thuat toan quay lui cho bai toan doi tien
#include<bits/stdc++.h>
using namespace std;
class money
{
	int n,a[100],x[100],M,res=INT_MAX,p[100];  //x cac to, p phuong an tot nhat
	void TRY(int k,int t,int T)//gia su da di duoc x1...xk co x1+..xk=t va a1x1+...akxk=T
	{
		if(k==n-1)
		{
			if((M-T)%a[n]==0)
			{
				x[n]=(M-T)/a[n]; 
				if(res>t+x[n]) 
				{
					res=t+x[n];
					for(int i=0;i<=n;i++) p[i]=x[i];
				} 
			}
			return;
		}
		for(x[k+1]=0;T+a[k+1]*x[k+1]<=M && t+x[k+1]<res;x[k+1]++) TRY(k+1,t+x[k+1],T+a[k+1]*x[k+1]);
	}
	public:	void sol()
	{
		cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
		cin>>M;
		TRY(0,0,0);
		if(res==INT_MAX) cout<<"\nKhong doi duoc";
		else 
		{
			cout<<"\nSo to it nhat "<<res<<"\n"<<M<<" = ";
			for(int i=1;i<n;i++) cout<<p[i]<<'*'<<a[i]<<"+"; cout<<p[n]<<"*"<<a[n];
		}
	}
};
int main()
{
	money M; M.sol();
}


