#include<bits/stdc++.h>
using namespace std;
void dfs(string x,string y,vector<string> &res)
{
	if(x=="" || y=="") return;
	if(x.back()==y.back()) 
	{
		char c=x.back();
		dfs(x.substr(0,x.length()-1),y.substr(0,y.length()-1),res);
		if(res.size()) for(auto &z:res) z.push_back(c);
		else res.push_back(string(1,c));
		return;
	}
	vector<string> res1,res2;
	dfs(x.substr(0,x.length()-1),y,res1);
	dfs(x,y.substr(0,y.length()-1),res2);
	int k=0;
	for(auto z:res1) if(k<z.length()) k=z.length();
	for(auto z:res2) if(k<z.length()) k=z.length();
	for(auto z:res1) if(z.length()==k)res.push_back(z);
	for(auto z:res2) if(z.length()==k)res.push_back(z);
}
int main()
{
	string x="BDCBADBA",y="ABACDBAD";//"abacab",y="cavadbdasf";
	cin>>x>>y;
	vector<string> res;
	dfs(x,y,res);
	map<string,bool> M;
	for(auto z:res) M[z]=true;
	for(auto z:M) cout<<z.first<<"\n";
}


