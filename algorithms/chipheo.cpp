#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		long long n;
		cin>>n;
		cout<<n%M*(n+1)%M*(n+2)%M*166666668%M<<"\n";
	}
}


