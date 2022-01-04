#include<bits/stdc++.h>
using namespace std;
class BCA
{
	int n,m,C[35][35]={},res=35,X[35]={},p[15]={}; 
	map<int,set<int>> A;  //Mon hoc do nhung ai day
	// C mon xung dot cac mon,X-quay lui, p-so mon duoc phan
	public:void sol()
	{
		int k,u,v;
		cin>>m>>n;
		for(int i=1;i<=m;i++)
		{
			cin>>k;
			while(k--) {cin>>u;	A[u].insert(i);}
		}
		cin>>k;
		while(k--) {cin>>u>>v; C[u][v]=C[v][u]=1;}
		for(int i=1;i<=n;i++)
		if(A[i].size()==1) 
		{
			int z=*A[i].begin();
			X[i]=z; 
			p[z]++;
			for(int j=1;j<=n;j++)
			if(C[j][i]) A[j].erase(z); 
		}
		TRY(0);
		cout<<res;
	}
	void TRY(int k)
	{
		if(k==n) res=*max_element(p+1,p+m+1);
		else
		{
			if(X[k+1]) TRY(k+1);
			else
			for(int t=1;t<=m;t++)
			if(A[k+1].find(t)!=A[k+1].end() && p[t]<res-1)
			{
				bool ok=1;
				for(int j=1;j<=k;j++) if(X[j]==t && C[j][k+1]==1) {ok=0;break;}
				if(ok) 
				{
					X[k+1]=t;
					p[t]++;
					TRY(k+1);
					p[t]--;
					X[k+1]=0;
				}
				
			}
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	BCA B;
	B.sol();
}


