#include<bits/stdc++.h>
using namespace std;
int nhan(int a,int b) {return max(a,b);}
int main()
{
	int a[]={4,7,2,8,1,6,3,5},n=8;
	int b[n];
	partial_sum(a,a+n,b,nhan);
	for(int x:b) cout<<x<<" ";
}


