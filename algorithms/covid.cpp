//covid
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,u,v;
	map<int,set<int> > A;  //A[i]= tap nhung nguoi tiep xuc voi i
	cin>>n>>m;
	while(m--) {cin>>u>>v; A[u].insert(v); A[v].insert(u);}
//	for(int i=1;i<=n;i++){cout<<"\n"<<i<<" : ";for(auto j:A[i]) cout<<j<<" ";}
	int F[n+5]={};
	cin>>F[0];
	queue<int> Q;
	map<int,int> M;
	for(int i=1;i<=F[0];i++) {cin>>u; Q.push(u); M[u]=0;}
	while(Q.size())
	{
		u=Q.front(); Q.pop();
		for(int v:A[u])
		if(M.find(v)==M.end())
		{
			M[v]=M[u]+1;
			Q.push(v);
			F[M[v]]++;
		}
	}
	for(int i=0;F[i]!=0;i++) cout<<"F"<<i<<": "<<F[i]<<"\n";
}


