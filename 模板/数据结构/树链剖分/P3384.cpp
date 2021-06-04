#include <bits/stdc++.h>

using namespace std;
const int maxn=200000+10;
int n,m,r,mod;
int e,beg[maxn],nex[maxn],to[maxn],w[maxn],wt[maxn];
int a[maxn<<2],laz[maxn<<2];
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn],deep[maxn],head[maxn]; 
int res=0;
struct node{
	int v,nxt;
}edge[maxn<<2];

void addedge(int u,int v)
{
	edge[++e].nxt = head[u];
	edge[e].v = v;
	head[u] = e;
}
inline void pushdown(int p,int k) {
	laz[p<<1] += laz[p];
	laz[p<<1|1] += laz[p];
	a[p<<1] += laz[p] * (k - (k >> 1));
	a[p<<1|1] += laz[p] * (k >> 1);
	a[p<<1] %= mod;
	a[p<<1|1] %= mod;
	laz[p] = 0;
}
inline void build(int p,int l,int r) {
	if(l == r) {
		a[p] = wt[l];
		if(a[p] > mod) a[p] %= mod;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1,mid+1,r);
	a[p] = (a[p << 1] + a[p << 1 | 1]) % mod;
}
inline void query(int p,int l,int r,int L,int R) {
	if(L <= l && r <= R) {
		res += a[p];
		res %= mod;
		return;
	}
	else {
		int mid = (l + r) >> 1;
		if(laz[p]) pushdown(p,r-l+1);
		if(L <= mid) query(p<<1,l,mid,L,R);
		if(R > mid) query(p<<1|1,mid+1,r,L,R);
	}
}
inline void update(int p,int l,int r,int L,int R,int k) {
	if(L <= l && r <= R) {
		laz[p] += k;
		a[p] += k * (r-l+1); 
	} 
	else {
		int mid = (r + l) >> 1;
		if(laz[p]) pushdown(p,r-l+1);
		if(L <= mid) update(p<<1,l,mid,L,R,k);
		if(R > mid) update(p<<1|1,mid+1,r,L,R,k);
		a[p] = (a[p<<1] + a[p<<1|1]) % mod;
	}
}
void dfs1(int p,int fath,int dep)
{
	siz[p] = 1;
	deep[p] = dep;
	fa[p] = fath;
	int maxson = -1;
	for(int i = head[p]; i ; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fath) {
			continue;
		}
		dfs1(v,p,dep+1);
		siz[p] += siz[v];
		if(siz[v] > maxson) {
			son[p] = v;
			maxson = siz[v];
		}
	}
}
void dfs2(int x,int topf)
{
	id[x] = ++cnt;
	wt[cnt] = w[x];
	top[x] = topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i = head[x]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa[x] || v == son[x]) continue;
		dfs2(v,v);
	}
}
inline int qRange(int x,int y)
{
	int ans = 0;
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]]) swap(x,y);
		res = 0;
		query(1,1,n,id[top[x]],id[x]);
		ans += res;
		ans %= mod;
		x = fa[top[x]];
	}
	if(deep[x] > deep[y]) swap(x,y);
	res = 0;
	query(1,1,n,id[x],id[y]);
	ans += res;
	return ans % mod;
}
inline int qSon(int x) {
	res = 0;
	query(1,1,n,id[x],id[x] + siz[x]-1);
	return res;
}
inline void updRange(int x,int y,int k) {
	k %= mod;
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]]) swap(x,y);
		update(1,1,n,id[top[x]],id[x],k);
		x = fa[top[x]];
	}
	if(deep[x] > deep[y]) swap(x,y);
	update(1,1,n,id[x],id[y],k);
}
inline void updSon(int x,int k)
{
	update(1,1,n,id[x],id[x]+siz[x]-1,k);
}
int main()
{
	cin >> n >> m >> r >> mod;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for(int i = 1; i < n; i++) {
		int a,b;
		cin >> a >> b;
		addedge(a,b);
		addedge(b,a);
	}
	dfs1(r,0,1);
	dfs2(r,r);
	build(1,1,n);
	while(m--) {
		int k,x,y,z;
		cin >> k;
		if(k == 1) {
			cin >> x >> y >> z;
			updRange(x,y,z);
		}
		else if(k == 2) {
			cin >> x >> y;
			cout << qRange(x,y) << "\n";
		}
		else if(k == 3) {
			cin >> x >> y;
			updSon(x,y);
		}
		else {
			cin >> x;
			cout << qSon(x) << "\n";
		}
	}
	return 0;
}