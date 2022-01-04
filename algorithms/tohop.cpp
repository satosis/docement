//Tinh To hop chap K cua n
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k,n,C=1;					//3 + 1
	cin>>k>>n;							//2
	//if(k<n-k) k=n-k;					
	for(int i=k+1;i<=n;i++) C*=i;		//3 + (n-k)*4 + 1 
	for(int i=2;i<=n-k;i++) C/=i;		//2 +  (n-k-1)* 5 +2
	cout<<C;							//1
}
//Do phuc tap ve khong gian K(n) = sizeof(long long)*3 + sizeof(int)*2
//Do phuc tap ve thoi gian  Omega(1) = T(n) = 15+ (n-k)*4+(n-k)*5-5 = (n-k)*9+10 = O(n)


