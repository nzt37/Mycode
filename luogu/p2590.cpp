#include <bits/stdc++.h>
#define mid ((r + l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define inf 1000000000
using namespace std;
const int maxn = 2e5 + 6;

int n,q;
int maxx[maxn<<2],lazy[maxn],w[maxn<<2],a[maxn<<2];
int head[maxn],e;
int cnt,top[maxn],dep[maxn],son[maxn],siz[maxn],fa[maxn],id[maxn],wt[maxn];

struct node{
	int v,next;
}edge[maxn<<1];

void addedge(int u,int v) {
	edge[++e].next = head[u];
	edge[e].v = v;
	head[u] = e;
}
void build(int p,int l,int r) {
	if( l == r) {
		a[p] = wt[l];
		maxx[p] = wt[l];
		return;
	}
	build(lson);
	build(rson);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
	a[p] = a[p<<1] + a[p<<1|1]; 
}
void dfs1(int p,int fath,int deep) {
	dep[p] = deep;
	fa[p] = fath;
	siz[p] = 1;
	int maxson = -1;
	for(int i = head[p]; i; i = edge[i].next) {
		int v = edge[i].v;
		if(v == fath) continue;
		dfs1(v,p,deep+1);
		siz[p] += siz[v];
		if(siz[v] > maxson) {
			son[p] = v;
			maxson = siz[v];
		}
	}
}
void dfs2(int p,int topf) {
	id[p] = ++cnt;
	wt[cnt] = w[p];
	top[p] = topf;
	if(!son[p]) return;
	dfs2(son[p],topf);
	for(int i = head[p]; i; i = edge[i].next) {
		int v = edge[i].v;
		if(v == fa[p] || v == son[p]) continue;
		dfs2(v,v);
	}
}
inline int q_max(int p,int l,int r,int L,int R) {
	
	if(L <= l && r <= R) return maxx[p];
	int res = -inf;
//	pushdown(p,r-l+1);
	if(L <= mid) res = max(res,q_max(lson,L,R));
	if(R > mid) res = max(res,q_max(rson,L,R));
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
	a[p] = a[p<<1] + a[p<<1|1]; 
	return res;
	// cout << "dsf" << "\n";


}
inline int QMAX(int x,int y) {
	// cout << "cfsd" << "\n";
	int res = -inf;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		// cout << "fs" << "\n";
		res = max(res,q_max(1,1,n,id[top[x]],id[x]));
		// cout << "fds" << "\n";
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	res = max(res,q_max(1,1,n,id[x],id[y]));
	return res;
}
void change(int p,int l,int r,int x,int k) {
	if(l == r) {
		a[p] = k;
		maxx[p] = k;
		return;
	}
	//pushdown(p,r-l+1);
	if(x <= mid) change(lson,x,k);
	else change(rson,x,k);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
	a[p] = a[p<<1] + a[p<<1|1]; 

}
inline int q_add(int p,int l,int r,int L,int R) {
	int res = 0;
	if(L <= l && r <= R) {
		return a[p];
	}
	//pushdown(p,r-l+1);
	if(L <= mid) res += q_add(lson,L,R);
	if(R > mid) res += q_add(rson,L,R);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
	a[p] = a[p<<1] + a[p<<1|1]; 
	return res;
}
inline int QADD(int x,int y) {
	int res = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res += q_add(1,1,n,id[top[x]],id[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])  swap(x,y);
	res += q_add(1,1,n,id[x],id[y]);
	return res;
}
int main()
{
	cin >> n ;
	for(int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		addedge(u,v);
		addedge(v,u);
	} 
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	fa[1] = 1;
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	// for(int i = 1; i <= n; i++) {
	// 	cout << "maxx " << maxx[i] << " add" << a[i] << "\n"; 
	// }
	cin >> q;
	string s;
	while(q--) {
		int x,y;
		cin >> s >> x >> y;
		//cout << "fsd" << "\n";
		if(s[1] == 'M') {
		//	cout << "fsdf" << "\n";
			cout << QMAX(x,y) << "\n";
			//cout << "fds" << "\n";
			
		}
		 if(s[1] == 'S') {
			cout << QADD(x,y) << "\n";
		}
		if(s[1] == 'H') {
			change(1,1,n,id[x],y);
		}
	}
	return 0;
}
/*
 4
1 2
2 3
4 1
4 2 1 3
12
QMAX 3 4
QMAX 3 3
QMAX 3 2
QMAX 2 3
QSUM 3 4
QSUM 2 1
CHANGE 1 5
QMAX 3 4
CHANGE 3 6
QMAX 3 4
QMAX 2 4
QSUM 3 4
 */