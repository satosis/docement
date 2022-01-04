#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,M;
	cin>>n>>M;
	int a[n];
	for(int &x:a) cin>>x;
	sort(a,a+n,greater<int>());  //nlogn
	int res=0;
	for(int x:a)
	{
		res+=M/x;
		M%=x;
	}
	if(!M) cout<<"\nSo to it nhat "<<res;
	else cout<<"\nKhong doi duoc";
}


