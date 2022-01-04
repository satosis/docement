//Fecma
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first
#define y second
double kc(Diem A,Diem B){A.x-=B.x; A.y-=B.y;return sqrt(A.x*A.x+A.y*A.y);}
Diem Fecma(Diem A,Diem B,Diem C)
{
	double d=10;
	Diem M={(A.x+B.x+C.x)/3,(A.y+B.y+C.y)/3};
	double res=kc(M,A)+kc(M,B)+kc(M,C);
	while(d>1e-8)
	{
		Diem NEXT[4]={{M.x+d,M.y},{M.x-d,M.y},{M.x,M.y+d},{M.x,M.y-d}};
		for(auto N:NEXT)
		{
			double k=kc(N,A)+kc(N,B)+kc(N,C);
			if(k<res) {res=k;M=N;d*=2; break;}
		}
		d/=2;
	}
	return M;
}
int main()
{
	Diem A,B,C;  cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
	Diem N= Fecma(A,B,C);
	cout<<setprecision(20)<<fixed;
	cout<<"Toa do can tim ("<<N.x<<","<<N.y<<")";
}


