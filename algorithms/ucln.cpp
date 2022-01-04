//Nhap a,b>0 tim ucln
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	buoc1:
			cout<<"Nhap a : "; cin>>a;
			cout<<"Nhap b : "; cin>>b;
	buoc2:  if(a<=0 || b<=0) goto buoc1;
			if(a>b) {a=a-b; goto buoc2;}	
			if(a<b) {b=b-a; goto buoc2;}	
	buoc3:  cout<<"uoc chung lon nhat "<<a;
}


