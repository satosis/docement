//counting sort -> O(n)
//Cho xau ky tu gom cac ky tu chu cai tieng anh thuong, hay sap xep tang dan
//anhban -> aabhnn
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char x[100005];
	scanf("%s",x);
	int d[130]={};    //d[97]=d['a']=2	
	for(char *p=x;*p;p++) d[*p]++;  //dem tan suat
	char *p=x;
	for(char c='a';c<='z';c++)        //O(26*n)->O(n)
		while(d[c]) {*p++=c;d[c]--;}
	printf("%s",x);		
}


