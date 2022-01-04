#include<bits/stdc++.h>
using namespace std;

class bus
{
	int N,Q,x[20005],d[20005]={},dem=0;
	void TRY(int k,int q)  //da co x0,x1..xk-1 co k phan tu
	{
		if(k==2*N) 
		{
			cout<<"\n"<<++dem<<" : ";
			for(int i=0;i<k;i++) cout<<(x[i]>N?-x[i]:x[i])<<" ";
			return;
		} 
		for(int t=(q==Q?N+1:1);t<=2*N;t++)
		if(d[t]==0 && (t<=N || (t>N && d[t-N]==1)))
		{
			d[t]=1;
			x[k]=t;
			TRY(k+1,q+(t>N?-1:1));
			d[t]=0;
		}
	}
	public:
	void sol()
	{
		cin>>N>>Q;
		TRY(0,0);
	}
};

int main()
{
	bus B;
	B.sol();
}


