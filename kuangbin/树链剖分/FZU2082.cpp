#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn<<2],lazy[maxn<<2];
int top[maxn],siz[maxn],son[maxn],w[maxn],wt[maxn],id[maxn],dep[maxn];
int head[maxn],cnt,e;
int fa[maxn];
struct node{
	int v,next;
}edge[maxn];
void addedge(int u,int v) {
	edge[++e].next = head[u];
	edge[e].v = v;
	head[u] = e; 
}
void build(int p,int l,int r) {
	if(l == r ) {
		a[p] = w[l];
		return;
	}
	build(lson);
	build(rson);
	a[p] = a[p<<1] + a[p << 1 | 1];
}
void pushdown(int p,int k) {
	if(lazy[p] >= 0) {
		a[p<<1] = a[p<<1|1] = lazy[p];
		lazy[p<<1] = lazy[p<<1|1] = lazy[p];
		lazy[p] = -1;
	}
}
void dfs1(int p,int fath,int deep) {
	siz[p] = 1;
	fa[p] = fath;
	dep[p] = deep;
	int maxson = -1;
	for(int i = head[p] ;i ; i = edge[i].next) {
		int v=  edge[i].v;
		if(v == fath) continue;
		dfs1(v,p,deep+1);
		siz[p] += siz[v];
		if(siz[v] > maxson) {
			maxson = siz[v];
			son[p] = v;
		}
	}
}
void dfs2(int p,int topf) {
	id[++cnt] = p;
	wt[cnt] = w[p];
	top[p] = topf;
	if(!son[p]) return;
	dfs2(son[p],topf);
	for(int i = head[p]; i ;i = edge[i].next) {
		int v = edge[i].v;
		if(v == fa[p] || v == son[p]) return;
		dfs2(v,v);
	}
}
inline void change(int p,int l,int r,int x,int k) {
	if(l == r) {
		a[x] = k;
		// lazy[p] = k;
		return;
	} 
	if(x <= mid) change(lson,x,k);
	else change(rson,x,k);
	a[p] = a[p<<1] + a[p<<1|1];
}
inline int qadd(int p,int l,int r,int L,int R) {
	if(L <= l && r <= R) {
		return a[p];
	}
	int res = 0;
	if(l <= mid) res += qadd(lson,L,R);
	if(R > mid) res += qadd(rson,L,R);
	return res;
}
inline int QADD(int x,int y) {
	int res = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res += qadd(1,1,n,id[top[x]],id[x]);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	res += qadd(1,1,n,x,y);
	return res;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	// while(m--) {
	// 	int x,y,z;
	// 	cin >> x >> y >> z;
	// 	if(x == 0) {
	// 		change(1,1,n,y,z);
	// 	}
	// 	else {
	// 		cout << QADD(y,z) << "\n";
	// 	}
	// }		
	return 0;
}
