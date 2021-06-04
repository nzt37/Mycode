#include <bits/stdc++.h>
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r

using namespace std;
const int maxn = 2e5 + 6;
int head[maxn],cnt,e,nxt[maxn],to[maxn];
int a[maxn<<2],fa[maxn],siz[maxn],top[maxn],dep[maxn],son[maxn];
int w[maxn],wt[maxn],id[maxn],u[maxn],v[maxn],hs[maxn];
int lazy[maxn<<2],tag[maxn<<2],maxx[maxn<<2],n;
struct node{
	int v,w,next;
}edge[maxn<<1];
void addedge(int u,int v,int w) {
	edge[++e].next = head[u];
	edge[e].v = v;
	edge[e].w = w;
	head[u] = e;
}
void dfs1(int p,int fath,int deep) {
	siz[p] = 1;
	fa[p] = fath;
	dep[p] = deep;
	int maxson = -1;
	for(int i = head[p]; i ; i = edge[i].next) {
		int v = edge[i].v;
		if(v == fath) return;
		w[v] = edge[i].w;
		dfs1(v,p,deep+1);
		siz[p] += siz[v];
		if(maxson < siz[v]) {
			maxson = siz[v];
			son[p] = v;
		}
	}
}
void dfs2(int p,int topf) {
	id[p] = ++cnt;
	wt[cnt] = w[p];
	top[p] = topf;
	if(!son[p]) return;
	dfs2(son[p],topf);
	for(int i = head[p]; i ;i = edge[i].next) {
		int v = edge[i].v;
		if(v == fa[p] || v == son[p]) { continue;}
		dfs2(v,v);
	}
}
inline void pushdown(int p,int k) {
	if(tag[p] >= 0) {
		lazy[p<<1] = lazy[p<<1|1] = 0;
		maxx[p<<1] = maxx[p<<1|1] = tag[p<<1] = tag[p<<1|1] = tag[p];
		tag[p] = -1;
	}
	if(lazy[p]) {
		lazy[p<<1] += lazy[p];
		lazy[p<<1|1] += lazy[p];
		maxx[p<<1] += lazy[p];
		maxx[p<<1|1] += lazy[p];
		lazy[p] = 0; 
	}
}
inline void build(int p,int l,int r) {
	if(l == r) {
		maxx[p] = wt[l];
		return;
	}
	build(lson);
	build(rson);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
}
int query(int p,int l,int r,int L,int R) {
	if(L <= l && r <= R) return maxx[p];
	int res = 0;
	pushdown(p,r-l+1);
	if(L <= mid) res = max(res,query(lson,L,R));
	if(R > mid) res = max(res,query(rson,L,R));
	return res;
}
inline int tmax(int x,int y) {
	int res = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res = max(res,query(1,1,n,id[top[x]],id[x]));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	res = max(res,query(1,1,n,id[x]+1,id[y]));
	return res;
}
void qAdd(int p,int l,int r,int L,int R,int k) {
//	cout << "fcdsfc" << "\n";
	if(L <= l && r <= R) {
		lazy[p] += k;
		maxx[p] += k;
		return;
	}
	pushdown(p,r-l+1);
	if(L <= mid)qAdd(lson,L,R,k);
	if(R > mid)qAdd(rson,L,R,k);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
}
void tAdd(int x,int y,int z) {
	//cout << "dsds" << "\n";
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		qAdd(1,1,n,id[top[x]],id[x],z);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	qAdd(1,1,n,id[x]+1,id[y],z);
}

void qCover(int p,int l,int r,int L,int R,int k) {
	if(L <= l && r <= R) {
		maxx[p] = k;
		tag[p] = k;
		lazy[p] = 0;
		return;
	}
	//cout << "dsdsdsddsdsds " << maxx[2]  << " " << p << "\n"; 
	pushdown(p,r-l+1);
	//cout << "dsdsdsd " << maxx[2]  << " " << p << "\n"; 
	if(L <= mid) qCover(lson,L,R,k);
	if(R > mid) qCover(rson,L,R,k);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);

}
void tCover(int x,int y,int z) {
	
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		qCover(1,1,n,id[top[x]],id[x],z);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	qCover(1,1,n,id[x]+1,id[y],z);

}
void Change(int p,int l,int r,int x,int k) {
	if(l == r) {
		maxx[p] = k;
		lazy[p] = 0;
		tag[p] = k;
		return;
	}
	pushdown(p,r-l+1);
	if(x <= mid) Change(lson,x,k);
	else Change(rson,x,k);
	maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
}
int main()
{

	memset(tag,-1,sizeof(tag));
	cin >> n;
	for(int i = 1; i < n; i++) {
		int w;
		cin >> u[i] >> v[i] >> w;
		addedge(u[i],v[i],w);
		addedge(v[i],u[i],w);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i = 1; i < n; i++) {
		if(fa[u[i]] == v[i]) hs[i] = u[i];
		else hs[i] = v[i];
	}
	while(1) {
		string s;
		cin >> s;
		int x,y,z;
		if(s[0] == 'S') break;
		if(s[0] == 'M') {
			cin >> x >> y;
			cout << tmax(x,y) << "\n";
		}
		else if(s[0] == 'A') {
			//cout << "dsacd" << "\n";
			cin >> x >> y >> z;
			
			tAdd(x,y,z);
		}
		else if(s[1] == 'o') {
			cin >> x >> y >> z;
			tCover(x,y,z);
			//cout << "dsa" << "\n";
		}
		else {
			cin >> x >> y;
			Change(1,1,n,id[hs[x]],y);
		}
	}
	return 0;
}