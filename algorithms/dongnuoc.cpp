//dong nuoc
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> TT;  //first-so nuoc can 1, second-so nuoc can 2
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if((k>n && k>m) || k%__gcd(n,m)) {cout<<"Khong dong duoc nuoc"; return 0;}
	map<TT,TT> M;  //TT first duoc moi boi TT second vao hang doi
	queue<TT> Q;
	Q.push({0,0}); 
	while(Q.size())
	{
		TT u=Q.front(); Q.pop();
		int x=u.first,y=u.second,z=x+y;
		TT Next[]={{0,y},{n,y},{x,0},{x,m},{max(0,z-m),min(z,m)},{min(z,n),max(0,z-n)}};
		for(TT v:Next)
		if(M.find(v)==M.end())
		{
			M[v]=u;
			Q.push(v);
			if(v.first==k||v.second==k) 
			{
				stack<TT> S;
				while(v.first+v.second>0) {S.push(v); v=M[v];}
				cout<<"(0,0)";
				while(S.size()) {cout<<"->("<<S.top().first<<","<<S.top().second<<")"; S.pop();}
				return 0;
			}
		}
	}
}


