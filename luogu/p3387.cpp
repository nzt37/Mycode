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
int a[maxn];
int dfn[maxn],head[maxn],cnt,col[maxn],sta[maxn],top,tot;
int dep,f[maxn],p,ans[maxn],in[maxn],low[maxn],vis[maxn];
std::vector<int> ed[maxn];
struct node{
	int v,next,u;
}e[maxn<<1];
void add(int u,int v) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].u = u;
	head[u] = cnt;
}
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
			low[u] = min(low[u],low[v]);
		}
	}
	if(dfn[u] == low[u]) {
		col[u] = u;
		vis[u] = 0;
		while(sta[top] != u) {
			col[sta[top]] = u;
			a[u] += a[sta[top]];
			vis[sta[top--]] = 0;
		}
		top--;
	}
}
int topo() {
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(!in[i] && col[i] == i) {
			q.push(i); 
			f[i] = a[i];
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < ed[u].size(); i++) {
			int v = ed[u][i];
			f[v] = max(f[v],f[u]+a[v]);
			in[v]--;
			if(in[v] == 0) {
				q.push(v);
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum = max(sum,f[i]);
	}
	return sum;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for(int j = 1; j <= m; j++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	for(int i = 1; i <= m; i++) {
		int x = col[e[i].u];
		int y = col[e[i].v];
		if(x != y) {
			in[y]++;
			ed[x].PB(y);
		}
	}
	cout << topo() << "\n";
	return 0;
}