#include<bits/stdc++.h>
using namespace std;
#define rr 1.61034
struct node
{
	int elem;
	int n;
	node *L,*R;
	node(int x,node *_L=0,node *_R=0)
	{
		elem=x;
		L=_L;
		R=_R;
		n=1+(L?L->n:0)+(R?R->n:0);
	}	
};
void rotate_right(node *&H)
{
	if(!H->L) return;
	node *p=H->L;
	H->L=p->R;
	p->R=H;
	H=p;		
}
void rotate_left(node *&H)
{
	if(!H->R) return;
	node *p=H->R;
	H->R=p->L;
	p->L=H;
	H=p;		
}
void add(node *&H,int x)
{
	if(!H) H=new node(x);
	else 
	{
		H->n++;
		add(x<H->elem?H->L:H->R,x);
		if(H->L && H->R) 
		{
			if(H->L->n>rr*H->R->n) rotate_right(H);
			else if(rr*H->L->n<H->R->n) rotate_left(H);
		}
	}
}
int Min(node*H){return H->L?Min(H->L):H->elem;}
int Max(node*H){return H->R?Max(H->R):H->elem;}
void remove(node *&H,int x)
{
	if(!H) return;
	if(H->elem==x) 
	{
		if(!H->L) H=H->R;
		else if(!H->R) H=H->L;
		else
		{
			H->elem=Max(H->L);
			remove(H->L,H->elem);
			H->n--;
		}
	}
	else remove(x<H->elem?H->L:H->R,x);
	if(H && H->L && H->R) 
	{
		if(H->L->n>rr*H->R->n) rotate_right(H);
		else if(rr*H->L->n<H->R->n) rotate_left(H);
	}
}
int main()
{
//	freopen("tv.txt","r",stdin);
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,x;
	cin>>n>>x;
	cout<<x<<" ";
	node *T=new node(x);
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		if(i%2==0) 
		{
			if(x>=T->elem) add(T->R,x);
			else if(!T->L) T=new node(x,0,T);
			else
			{
				add(T->R,T->elem); 
				int k=Max(T->L);
				if(x>=k) T->elem=x;
				else
				{
					T->elem=k;
					remove(T->L,k);
					add(T->L,x);
					
				}
			}
		}
		else
		{
			if(x<=T->elem) add(T->L,x);
			else if(!T->R) T=new node(x,T,0);
			else
			{
				add(T->L,T->elem); 
				int k=Min(T->R);
				if(x<=k) T->elem=x;
				else
				{
					T->elem=k;
					remove(T->R,k);
					add(T->R,x);
				}
			}
		}
		cout<<T->elem<<" ";
	}
}


