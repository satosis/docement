#include<bits/stdc++.h>
using namespace std;
int main()
{
	multiset<int,greater<int> > S;
	for(int x:{42,5,63,74,85,85,869,79,808,54,37,6,25,1,517,1626,347,42,85,54}) S.insert(x);
	multiset<int,greater<int> >::iterator it=S.find(85);
	//S.erase(85);
	S.erase(it);
	//for(tree::iterator it=T.begin();it!=T.end();it++) cout<<*it<<" ";
	for(auto z:S) cout<<z<<" ";


}


