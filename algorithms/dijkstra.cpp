//thuat toan Dijkstra
#include<bits/stdc++.h>
using namespace std;
map<int,int> P;
void inpath(int s,int f)
{
	if(s==f) cout<<s;
	else {inpath(s,P[f]); cout<<"->"<<f;}
}
int main()
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	//second-dinh, first-dodai tu xp den dinh second
	map<int,int> L;  //L[i] do dai duong di ngan nhat tu xp toi i
	int n,m,s;
	cin>>n>>m;
	vector< pair<int,int> > A[n+5];  //A[1] = <(16,2),(14,4)>	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w; 
		A[u].push_back({w,v});
	}
	cin>>s;
	for(int i=1;i<=n;i++) L[i]=1e9;
	L[s]=0;
	Q.push({0,s});
	while(Q.size())
	{
		pair<int,int> u=Q.top(); Q.pop();
		if(L[u.second]<u.first) continue; //bo qua dinh da xet co duong di tot hon
		for(auto v:A[u.second])
		if(u.first+v.first<L[v.second])
		{
			P[v.second]=u.second;
			L[v.second]=u.first+v.first;
			Q.push({u.first+v.first,v.second});
		}
	}
	for(int i=1;i<=n;i++)
	if(L[i]==1e9) cout<<"\nkhong di duoc tu "<<s<<" den "<<i<<"\n";
	else 
	{
		cout<<"\n"<<s<<" -> "<<i<<" ngan nhat "<<L[i]<<" : ";
		inpath(s,i);
	}
}


