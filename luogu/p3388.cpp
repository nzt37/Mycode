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
	int v,next;
}e[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],ans[maxn];
int dep = 0,tot = 0;
void tarjan(int u,int fa) {
	low[u] = dfn[u] = ++dep;
	int an = 0;
	for(int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(!dfn[v]) {
			tarjan(v,fa);
			low[u] = min(low[u],low[v]);
			if(u != fa && dfn[u] <= low[v]) {
				ans[u] = 1;
			}
			if(u == fa) {
				an++;
			}
		}
		low[u] = min(low[u],dfn[v]);
	}
	if(an >= 2 && u == fa) {
		ans[u] = 1;
	}
}
void add(int u,int v) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	for(int i = 1; i <= n; i++) {
		if(dfn[i] == 0) {
			tarjan(i,i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(ans[i]) {
			tot++;
		}
	}
	cout << tot << "\n";
	for(int i = 1; i <= n; i++) {
		if(ans[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}
/*
6 7
1 3
1 4
4 2
3 2
2 6
2 5
6 5
*/