#include<bits/stdc++.h>
#include"pq.cpp"
using namespace std;
struct ss{bool operator()(int a,int b) {return a%3==b%3?a>b:a%3>b%3;}};
int main()
{
//	priority_queue<int> Q;
//	priority_queue<int,vector<int>, greater<int> > Q;
	pq<int,ss > Q;
	for(int x:{4,8,3,2,4,7,2,8,5}) Q.push(x);
	while(Q.size())
	{
		cout<<Q.top()<<" ";
		Q.pop();
	}


}


