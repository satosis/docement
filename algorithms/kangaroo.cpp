#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int main()
{
	int n,a,c[MAX],u,v,res=-INT_MAX;
	cin>>n>>u>>v;
	deque<int> Q;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(i-u>=1 && c[i-u]>0) 
		{
			while(Q.size() && c[Q.back()]<=c[i-u]) Q.pop_back();
			Q.push_back(i-u);
		}
		if(Q.size() && i-Q.front()>v) Q.pop_front();
		if(Q.size()) c[i]=c[Q.front()]+a;
		else c[i]=a;
	}
	cout<<*max_element(c+1,c+n+1);
}
