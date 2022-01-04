#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k=13,n=37;							//2
	//cin>>k>>n;								//2
	long long C[n+1];						//2
	for(int i=0;i<=n;i++)					//
	{
		C[i]=1;
		for(int j=i-1;j>0;j--) C[j]+=C[j-1];
	}
	cout<<C[k];								//2
}
//Khong gian K(n)= (2+n+1)*sizeof(long long) +2sizeof(int)
//Thoi gian T(n)= 8+3+8*(n+1)+7n(n-1)/2	=3.5n^2+4.5n+19 = Theta(n^2) 


