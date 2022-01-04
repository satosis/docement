//pair - khai bao cac cau truc 2 thanh phan: diem, (hang,cot), trang thai cap doi
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first
#define y second
double dt(Diem A,Diem B) {return A.x*B.y-A.y*B.x;}
int main()
{
	Diem A,B,C;
	cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
	double s=dt(A,B)+dt(B,C)+dt(C,A);
	if(s==0) cout<<"Thang";
	else cout<<(s<0?"Phai":"Trai");
}


