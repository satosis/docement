#include<bits/stdc++.h>
using namespace std;
int main()
{
	multimap<int,int> M;  //map<pair<int,int> , bool>
	M.insert({4,5});
	M.insert({3,6});
	M.insert({4,7});
	for(auto m:M) cout<<m.first<<" "<<m.second<<"\n";

}


