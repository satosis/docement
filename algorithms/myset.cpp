#include<bits/stdc++.h>
using namespace std;
template <class TT>
struct node
{
	TT elem;
	bool color;  //1-red; 0-black
	node*L,*R,*F;
	node(TT x,node *_F=0) {elem=x; color=1; L=R=0;F=_F;}
};
template <class TT,class Cmp = less<TT> >
class Set
{
	private:
		list<TT> L;
		node<TT>*root;   //quan ly cay
		Cmp ss;
		int n;		  //dem so nut cua cay
		void left_rotate(node<TT>*&H)
		{
			node<TT>*p=H->R,*q=H->F,*r=p->L;
			H->R=r; if(r) r->F=H;
			p->F=q;
			if(q) H==q->L?q->L=p:q->R=p;
			else root=p;
			p->L=H; H->F=p;
			H=p;
		}
		void right_rotate(node<TT>*&H)
		{
			node<TT>*p=H->L,*q=H->F,*r=p->R;
			H->L=r; if(r) r->F=H;
			p->F=q;
			if(q) H==q->L?q->L=p:q->R=p;
			else root=p;
			p->R=H; H->F=p;
			H=p;
		}
		node<TT>*add(node<TT>*&H,TT x)
		{
			if(!H) return root=new node<TT>(x);
			if(H->elem==x) return 0;
			if(ss(x,H->elem)) {if(H->L) return add(H->L,x); return H->L=new node<TT>(x,H);}
			if(H->R) return add(H->R,x);
			return H->R=new node<TT>(x,H);
		}
		void conflict(node<TT>*p)
		{
			if(!p) return;
			if(p==root) {p->color=0; return;}
			if(p->F->color==0) return;
			node<TT>*o=p->F->F;
			if(o->L && o->R && o->L->color==o->R->color) {o->L->color=o->R->color=0;o->color=1; conflict(o); return;}
			node<TT>*q=p->F;
			if(q==o->L)
			{
				if(p==q->R) left_rotate(q);
				o->color=1;
				q->color=0;
				right_rotate(o);
			}
			else
			{
				if(p==q->L) right_rotate(q);
				o->color=1;
				q->color=0;
				left_rotate(o);
			}
		}
		void inorder(node<TT>*H,string s="\n")
		{
			if(!H) return;
			inorder(H->L,s+"\t");
			cout<<s<<H->elem<<":"<<H->color;
			inorder(H->R,s+"\t");
		}
		void in_order(node<TT>*H)
		{
			if(!H) return;
			in_order(H->L);
			L.push_back(H->elem);
			in_order(H->R);
		}
	public:
		typedef typename list<TT>::iterator  iterator;
		iterator begin()
		{
			L.clear();
			in_order(root);
			return L.begin();
		}
		iterator end() {return L.end();}
		Set() {root=0; n=0;}
		bool empty() {return n==0;}
		int size() {return n;}
		void insert(TT x) 
		{
			node<TT>*p=add(root,x);
			if(p) {n++;conflict(p);}
			//cout<<"\nthem "<<x<<"\n";
			//inorder(root);
		}
};

int main()
{
	Set<double,greater <double> > T;
	double a[]={42,5,63,74,85,85,8.69,79,808,54,37,6,25,1,517,16.26,347,42,85};
	for(double x:a) T.insert(x);
	//for(Set::iterator it=T.begin();it!=T.end();it++) cout<<*it<<" ";
	for(auto z:T) cout<<z<<" ";
}


