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
int lg[maxn],dep[maxn],fa[maxn][30],vis[maxn];
int n,m;
int head[maxn],cnt;
struct node{
	int v,next;
}e[maxn<<1];
void add(int u,int v) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
void dfs(int pos,int f)
{
    if(vis[pos]) return;
    vis[pos] = 1;
    dep[pos] = dep[f] + 1;
    fa[pos][0] = f;
    for(int i = 1; i <= lg[dep[pos]]; i++){
        fa[pos][i] = fa[fa[pos][i-1]][i-1];
    }
    for(int i = head[pos]; i ; i = e[i].next){
        dfs(e[i].v,pos);
    }
}
int lca(int a,int b)
{
    if(dep[a] < dep[b]){
        swap(a,b);
    }
    while(dep[a] > dep[b]){
        a = fa[a][lg[dep[a]-dep[b]]-1];
    }
    if(a == b) return a;
    for(int k = lg[dep[a]] - 1; k >= 0 ; k--){
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];

}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
	}
	for(int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	// for(int i = 1; i <= n; i++) {
	// 	cout << dep[i] << "\n";
	// }
	cin >> m;
	while(m--) {
		int a,b,x,y,k;
		cin >> x >> y >> a >> b >> k;
		int d1 = dep[b] + dep[a] - 2 * dep[lca(a,b)];
		int d2 = dep[a] + dep[x] - 2 * dep[lca(a,x)] + 1 + dep[y] + dep[b] - 2 * dep[lca(y,b)];
		int d3 = dep[b] + dep[x] - 2 * dep[lca(b,x)] + 1 + dep[y] + dep[a] - 2 * dep[lca(y,a)];
		// cout << d1 << d2 << d3 << "\n"; 
		if(k >= d1 && (k-d1) %2 == 0) {
			cout << "YES\n";
		}
		else if(k >= d2 && (k-d2) %2 == 0) {
			cout << "YES" << "\n";
		}
		else if(k >= d3 && (k-d3) %2 == 0) {
			cout << "YES" << "\n";
		}
		else
		cout << "NO" << "\n";
		// continue;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}
/*
9
3 9
3 4
7 2
6 9
5 3
6 2
8 3
1 9
1
5 4 7 8 3
*/