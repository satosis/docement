#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k,L,R;
	cin>>n>>k;
	long long a[n+5]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	partial_sum(a+1,a+n+1,a+1);
	while(k--)
	{
		cin>>L>>R;
		cout<<a[R]-a[L-1]<<"\n";
	}
}


