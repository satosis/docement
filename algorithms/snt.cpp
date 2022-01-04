//nhap n in ra cac so nguyen to nho hon bang n
#include<bits/stdc++.h>
using namespace std;

bool ktnt(int n)
{
	if(n==2) return 1;
	if(n<2 || n%2==0) return 0;
	for(int i=3;i*i<=n;i+=2) if(n%i==0) return 0;
	return 1;
} //O(sqrt(n))

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++) if(ktnt(i)) cout<<i<<" ";	
	//T(n)=O(n*sqrt(n)) =O(n^1.5)
}


