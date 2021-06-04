#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
struct node{
	int u,v,next;
}e[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],sta[maxn],vis[maxn];
int c[maxn],an[maxn],du[maxn],top,tot;
void add(int u,int v) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].u = u;
	head[u] = cnt;
}
int dep = 0;
void tarjan(int u) {
	dfn[u] = low[u] = ++dep;
	vis[u] = 1;
	sta[++top] = u;
	for(int i = head[u]; i ;i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else {
			if(vis[v])
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		c[u] = ++tot;
		vis[u] = 0;
		while(sta[top] != u) {
			c[sta[top]] = tot;
			vis[sta[top--]] = 0;
		}
		top--;
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
	}	
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	for(int i = 1; i <= n; i++) {
		an[c[i]]++;
		// cout << c[i] << "\n";
		for(int j = head[i]; j; j = e[j].next) {
			if(c[e[j].v] != c[i]) {
				du[c[i]]++;
			}
		}
	}
	int mx = 0,p = 0;
	for(int i = 1; i <= tot; i++) {
		if(du[i] == 0) {
			mx++;
			p = i;
		}
	}
	// cout << mx << "\n";
	if(mx > 1) {
		cout << 0 << "\n";
	}
	else {
		cout << an[p] << "\n";
	}
	return 0;
}