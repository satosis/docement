#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,c[100005]={-INT_MAX},k=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a;
		if(a>c[k]) c[++k]=a;
		else
		{
			int *p=lower_bound(c,c+k+1,a);
			*p=a;
		}
	}
	cout<<k;
}


