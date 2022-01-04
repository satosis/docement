#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	unordered_map<string,int> M;
	cin>>n;
	while(n--)
	{
		string x,y;
		cin>>x>>y;
		if(x=="find") cout<<M[y]<<"\n";
		else for(int i=1;i<y.length();i++) M[y.substr(0,i)]++;
	}
}


