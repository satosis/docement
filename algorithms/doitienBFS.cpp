#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> TT;   //first-tien,second-to
struct ss
{
	bool operator()(TT u,TT v)
	{
		if(u.second==v.second) return u.first<v.first;   //to bang nhau thi ut tien lon hon
		return u.second>v.second;  //ut to it hon	
	}	
};
int main()
{
	priority_queue<TT,vector<TT>, ss> Q;
	map<int,int> D;  //first-tien,second-to
	int n; cin>>n; int a[n]; for(int &x:a) cin>>x; //nhap so menh gia va cac menh gia
	int M; cin>>M;
	D[0]=0; //so tien 0 co 0 to
	Q.push({0,0});    
	while(Q.size() && D.find(M)==D.end())
	{
		TT u=Q.top(); Q.pop();
		for(int x:a)
		if(u.first+x<=M && D.find(u.first+x)==D.end())
		{
			D[u.first+x]=u.second+1;
			Q.push({u.first+x,u.second+1});
		}
	}
	if(D.find(M)==D.end()) cout<<"\nKhong doi duoc";
	else cout<<"\nSo to it nhat "<<D[M];
}


