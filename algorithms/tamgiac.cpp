#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first
#define y second
double bpkc(Diem A,Diem B)
{
	A.x-=B.x; A.y-=B.y;
	return sqrt(A.x*A.x+A.y*A.y);
}
Diem Find(Diem A,Diem B,Diem M)
{
	while(bpkc(A,B)>1e-8) 
	{
		Diem C={(A.x+B.x)/2,(A.y+B.y)/2};
		bpkc(M,A)>bpkc(M,B)?A=C:B=C;
	}
	return A;
}
int main()
{
	Diem A(-3,0),B(10,0),M(15,4);
	Diem N=Find(A,B,M);
	cout<<setprecision(20)<<fixed;
	cout<<"Toa do can tim ("<<N.x<<","<<N.y<<")";
}


