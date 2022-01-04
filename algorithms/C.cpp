#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,long long> Dic;
long long C(int k,int n)			//2
{
	if(Dic.find({k,n})!=Dic.end()) return Dic[{k,n}];
	if(k<=0 || k>=n) return Dic[{k,n}]=1;		//3
	return Dic[{k,n}]=C(k-1,n-1)+C(k,n-1);		//1+4
}
int main()
{
	cout<<C(13,37);
}
//Khong gian K(n) = K(n)=2*(1+2+4+...2^n)*[sizeof(int)+sizoef(long long)] =2*(2*2^n-1)*20 = O(2^n)
//Thoi gian T(n)= (2*2^n-1)*10 = O(2^n)


