#include<bits/stdc++.h>
using namespace std;
struct sudoku
{
	int a[9][9];
	void read(string fname)
	{
		ifstream fin(fname);   //mo file C++11
		for(int i=0;i<9;i++)
		for(int j=0;j<9;j++) 
		{
			char c;
			fin>>c;
			a[i][j]=c-'0';
		}
		fin.close();
	}
	void write()
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++) cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	bool check(int u,int v,int t)
	{
		for(int i=0;i<9;i++) if(a[u][i]==t || a[i][v]==t) return 0;
		for(int i=u/3*3;i<u/3*3+3;i++)
		for(int j=v/3*3;j<v/3*3+3;j++)
		if(a[i][j]==t) return 0;
	}
	void TRY(int u,int v)
	{
		if(u>8) {write(); return;}
		if(a[u][v]) TRY(u+v/8,(v+1)%9);
		else
		{
			for(int t=1;t<=9;t++)
			if(check(u,v,t))
			{
				a[u][v]=t; TRY(u+v/8,(v+1)%9);
				a[u][v]=0;
			}
		}
	}
};
int main()
{
	sudoku S; S.read("s.txt"); S.write();
	cout<<"\nKet qua \n"; S.TRY(0,0);
}


