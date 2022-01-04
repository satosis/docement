//map<A,B>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<string,int> M;
	int n;
	cin>>n;
	while(n--)
	{
		string x;
		cin>>x; 
		M[x]++;
	}
	for(auto m:M) cout<<m.first<<" "<<m.second<<"\n";
}


