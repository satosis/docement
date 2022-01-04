#include<bits/stdc++.h>
using namespace std;
double chiadoi(double a,double b, double f(double))
{
	while(b-a>1e-10)
	{
		double c=(a+b)/2;
		f(a)*f(c)<=0?b=c:a=c;
	}
	return (a+b)/2;
}
int main()
{
	cout<<"Pi = "<<setprecision(20)<<chiadoi(3,3.5,sin);

}


