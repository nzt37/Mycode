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
#define int long long
const int maxn = 2e5 + 10;

int n,m;
struct node{
	int v,w,next;
}e[maxn<<1];
int head[maxn],cnt;
int a[maxn],b[maxn],c[maxn],f[maxn][2];
ll ans = 0;
void add(int u,int v) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
void dfs(int x,int fa) {
	if(x != 1) a[x] = min(a[x],a[fa]);
	f[x][b[x]] += (b[x] != c[x]);
	for(int i = head[x]; i ; i = e[i].next) {
		int v = e[i].v;
		if(v == fa) continue;
		dfs(v,x);
		f[x][0] += f[v][0];
		f[x][1] += f[v][1];
	}
	int t = min(f[x][0],f[x][1]);
	ans += t*a[x] * 2;
	f[x][0] -= t;
	f[x][1] -= t;
}
signed main() {
	cin >> n;
	int s1 = 0,s2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		s1 += b[i],s2 += c[i];
	}
	for(int i = 1; i < n;i ++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	if(s1 != s2) {
		cout << -1 << "\n";
		return 0;
	}
	dfs(1,-1);
	cout << ans << "\n";
 	return 0;
}