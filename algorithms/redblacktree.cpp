#include<bits/stdc++.h>
using namespace std;

struct node
{
	int elem;
	bool color;  //1-red; 0-black
	node*L,*R,*F;
	node(int x,node *_F=0) {elem=x; color=1; L=R=0;F=_F;}
};
class tree
{
	private:
		list<int> L;
		list<int>::iterator curr;
		node *root;   //quan ly cay
		int n;		  //dem so nut cua cay
		void left_rotate(node *&H)
		{
			node *p=H->R,*q=H->F,*r=p->L;
			H->R=r; if(r) r->F=H;
			p->F=q;
			if(q) H==q->L?q->L=p:q->R=p;
			else root=p;
			p->L=H; H->F=p;
			H=p;
		}
		void right_rotate(node *&H)
		{
			node *p=H->L,*q=H->F,*r=p->R;
			H->L=r; if(r) r->F=H;
			p->F=q;
			if(q) H==q->L?q->L=p:q->R=p;
			else root=p;
			p->R=H; H->F=p;
			H=p;
		}
		node *add(node *&H,int x)
		{
			if(!H) return root=new node(x);
			if(x<H->elem) {if(H->L) return add(H->L,x); return H->L=new node(x,H);}
			if(H->R) return add(H->R,x);
			return H->R=new node(x,H);
		}
		void conflict(node *p)
		{
			if(p==root) {p->color=0; return;}
			if(p->F->color==0) return;
			node *o=p->F->F;
			if(o->L && o->R && o->L->color==o->R->color) {o->L->color=o->R->color=0;o->color=1; conflict(o); return;}
			node *q=p->F;
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
		void inorder(node *H,string s="\n")
		{
			if(!H) return;
			inorder(H->L,s+"\t");
			cout<<s<<H->elem<<":"<<H->color;
			inorder(H->R,s+"\t");
		}
		void in_order(node *H)
		{
			if(!H) return;
			in_order(H->L);
			L.push_back(H->elem);
			in_order(H->R);
		}
	public:
		typedef list<int>::iterator  iterator;
		iterator begin()
		{
			L.clear();
			in_order(root);
			return L.begin();
		}
		iterator end() {return L.end();}
		tree() {root=0; n=0;}
		int empty() {return n==0;}
		int size() {return n;}
		void insert(int x) 
		{
			n++;
			node *p=add(root,x);
			conflict(p);
			//cout<<"\nthem "<<x<<"\n";
			//inorder(root);
		}
};

int main()
{
	tree T;
	for(int x:{42,5,63,74,85,85,869,79,808,54,37,6,25,1,517,1626,347}) T.insert(x);
	//for(tree::iterator it=T.begin();it!=T.end();it++) cout<<*it<<" ";
	for(auto z:T) cout<<z<<" ";
}


