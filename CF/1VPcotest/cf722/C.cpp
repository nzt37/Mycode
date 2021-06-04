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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
std::vector<int> e[maxn];
int l[maxn],r[maxn];
ll f[maxn][2];
void dfs(int u,int fa) {
	f[u][1] = f[u][0] = 0;
	for(auto i : e[u]) {
		if(i == fa) continue;
		dfs(i,u);
		f[u][0] += max(f[i][0]+abs(l[i]-l[u]),f[i][1]+abs(r[i]-l[u]));
		f[u][1] += max(f[i][0]+abs(l[i]-r[u]),f[i][1]+abs(r[i]-r[u]));
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}
	for(int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].PB(v);
		e[v].PB(u);
	}
	dfs(1,1);
	cout << max(f[1][1],f[1][0]) << "\n";
	for(int i = 1; i <= n; i++) {
		e[i].clear();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}