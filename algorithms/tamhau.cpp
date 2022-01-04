//con hau
#include<bits/stdc++.h>
using namespace std;

map<int,bool> A,B,C;//A- danh dau cot, B-cheo chinh, C-chep phu
int d=0;
void TRY(int *x,int k,int n) //gia su co x1...x[k-1]
{
	if(k>n) 
	{
		cout<<"\n"<<setw(3)<<++d<<" : ";
		for(int i=1;i<=n;i++) cout<<"("<<i<<","<<x[i]<<") ";
	}
	else 
	for(int t=1;t<=n;t++)
	if(!A[t] && !B[t-k] && !C[t+k]) 
	{
		A[t]=B[t-k]=C[t+k]=1;
		x[k]=t; 
		TRY(x,k+1,n);
		A[t]=B[t-k]=C[t+k]=0;
	}
}
int main()
{
	int x[100];
	int n;
	cin>>n;
	B[0]=C[n+1]=1;
	TRY(x,1,n);
}


