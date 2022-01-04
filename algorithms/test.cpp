#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<int> A;
	A.insert(4);
	A.insert(5);
	A.insert(6);
	A.erase(3);
	for(auto x:A) cout<<x<<" ";

}


