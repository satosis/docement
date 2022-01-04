//Phuong phap monte-carlo tinh so pi
#include<bits/stdc++.h>
using namespace std;
double myran(){return (double)rand()/RAND_MAX;}
int main()
{
	srand(time(0));
	double res=0,n=1e8,x,y;
	for(int i=1;i<=n;i++) 
	{
		x=myran();
		y=myran();
		if(1/(x*x+1)>=y) res++;
	}
	cout<<setprecision(20)<<fixed<<res/n*4;
}


