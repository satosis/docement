#include<bits/stdc++.h>
using namespace std;
#ifndef __pq__cpp__
#define __pq__cpp__
template <class T>
struct node
{
	T elem;     //du lieu tai moi node
	int n;     	//so phan tu (node) trong cay
	node *L,*R;
	node(T x,node<T>*t=0,node<T>*p=0) 
	{
		elem=x;L=t;R=p;
		n=1+(L?L->n:0)+(R?R->n:0);
	}
};
template<class T,class K>
class pq
{
	node<T> *root;
	K ss;
	private:
		void add(node<T> *&H,T x)
		{
			if(!H) H=new node<T>(x);
			else if(ss(H->elem,x)) H=new node<T>(x,H);
			else 
			{
				H->n++;
				if(!H->L) H->L=new node<T>(x);
				else if(!H->R) H->R=new node<T>(x);
				else add(H->L->n<H->R->n?H->L:H->R,x);
			}
		}
		void remove(node<T> *&H)
		{
			if(H->n==1) H=0;
			else if(!H->L) H=H->R;
			else if(!H->R) H=H->L;
			else
			{
				H->n--;
				if(ss(H->R->elem,H->L->elem)) {H->elem=H->L->elem; remove(H->L);}
				else {H->elem=H->R->elem; remove(H->R);}
			}
		}
	public:
		pq() {root=0;}	
		int size() 	 {return root?root->n:0;}
		bool empty() {return !root;}
		void push(T x) {add(root,x);}
		void pop() {remove(root);}
		T top(){return root->elem;}
};
#endif


