#include<bits/stdc++.h>
using namespace std;
int C[1005][1005];
class Xau
{
	int n,m;
	char x[1000],y[1000];
	map<string,bool> Dic;
	void buocthuan()
	{
		for(int i=0;i<=n;i++) C[i][0]=0;  //cot dau
		for(int j=0;j<=m;j++) C[0][j]=0;  //hang dau
		for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++) 
		if(x[i]==y[j]) C[i][j]=C[i-1][j-1]+1; 
		else  C[i][j]=max(C[i-1][j],C[i][j-1]);
	}
	void buocnghich(int n,int m)
	{
		if(C[n][m]==0) return;
		while(C[n][m]==C[n-1][m]) n--;  //di len
		while(C[n][m]==C[n][m-1]) m--;  //di sang trai
		buocnghich(n-1,m-1);
		cout<<x[n];
	}
	public:void sol()
	{
		scanf("%s",x+1); n=strlen(x+1);
		scanf("%s",y+1); m=strlen(y+1);
		buocthuan();
		if(C[n][m]==0) {printf("khong co xau con chung"); return;}
		//cout<<"\nDo dai xau con chung dai nhat "<<C[n][m]<<"\n";
		//cout<<"\nXau con chung can tim : \n";
		//buocnghich(n,m);
		char z[200]={};
		TRY(n,m,z+C[n][m]-1,z);
		for(auto d:Dic) cout<<d.first<<"\n";
	}
	void TRY(int n1,int m1,char *kq,char *z)  //quaylui
	{
		if(C[n1][m1]==0) {/*printf("%s\n",z);*/ Dic[string(z)]=1; return;}
		if(C[n1][m1]==C[n1-1][m1]) TRY(n1-1,m1,kq,z);
		if(C[n1][m1]==C[n1][m1-1]) TRY(n1,m1-1,kq,z);
		if(x[n1]==y[m1])  { *kq=x[n1]; TRY(n1-1,m1-1,kq-1,z);} 
	}
};
int main()
{

//	freopen("a5.inp","r",stdin);
//	freopen("a5.out","w",stdout);
		Xau S;  S.sol();
}
