#include <bits/stdc++.h>

#define int long long
using namespace std;
int kekich = 0;
struct Node{
	int x;
	int y;
	int sm;
	Node *l,*r;
};
int get_sum(Node *a){
	if(a==NULL){
		return (0);
	}
	return (a->sm);
}
void update(Node *a){
	if(a!=NULL){
		a->sm = a->x+get_sum(a->l)+get_sum(a->r);
	}
}
Node *new_Node(int val) {
	Node *root = new Node;
	root->x= val;
	root->y=rand();
	root->l = NULL;
	root->r = NULL;
	root->sm = val;
	return(root);
}
Node *merge(Node *a,Node *b){
	if(a==NULL){
		return(b);
	} 
	if(b==NULL){
		return(a);
	}
	if(a->y>b->y){
		a->r = merge(a->r,b);
		update(a);
		return(a);
	} else {
		b->l = merge(a,b->l);
		update(b);
		return(b);
	}
}
void split(Node *a, int xx, Node *&t1,Node *&t2){
	if(a==NULL){
		t1 = NULL;
		t2 = NULL;
		return;
	}	
	if(a->x<=xx) {
		split(a->r,xx,a->r,t2);
		t1 = a;
	} else {
		split(a->l,xx,t1,a->l);
		t2 = a;
	}
	update(a);
}
int sm(Node *&a,int l, int r){
	Node *t1,*t2,*t3,*t4;
	split(a,l-1,t1,t2);
	split(t2,r,t3,t4);
	int ans = get_sum(t3);
	a = merge(t1,merge(t3,t4));
	return (ans);
}
int nexr(Node *&a){
	if(a->r==NULL){
		return(a->x);
	} else {
		return(nexr(a->r));
	}
}
void add(Node *&a, int xx) {
	Node *t1, *t2;
	Node *nw = new_Node(xx);
	split(a,xx,t1,t2);
	int xxx = -1000;
	if((t1!=NULL)){
		xxx = nexr(t1);
		
	} 
	if(xxx!=xx){
		t1 = merge(t1,nw);
	}	
	a = merge ( t1,t2);
}
void nexl(Node *a){
	if(a->l==NULL){
		kekich = a->x;
		cout<<a->x<<endl;
	} else {
		nexl(a->l);
	}
}
void next(Node *&a, int xx){
	Node *t1,*t2;
	split(a,xx,t1,t2);
//	cout<<t1<<" "<<t2<<endl;
	int xxx  = -10000;
 	if((t1!=NULL)){
		xxx = nexr(t1);
	}
	if(xxx==xx){
			kekich = xx;
			cout<<xx<<'\n';
	}  else {
	    if(t2==NULL){
	    	kekich = -1;
	    	cout<<-1<<'\n';
		} else {
			nexl(t2);
		}
	}
	a = merge(t1,t2);
}
void tree(Node *&a){
	if(a!=NULL){
		cout<<a->x<<" ";
		tree(a->l);
		tree(a->r);
	}
}
main() {
	Node *root = NULL;
	int n;
	cin>>n;
	int md =1e9;
	for(int i=0;i<n;i++){
		char s;
		cin>>s;
		int xx;
		cin>>xx;
		if(s=='+'){
			xx = (xx+kekich)%md;
			kekich = 0;
			add(root,xx);
			//tree(root);
		} else {
			next(root,xx);
		}
	}
}
