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
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define all(a) a.begin(),a.end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
std::vector<int> e[maxn];
int vis[maxn],f[maxn],d[maxn];
void solve() {
	CLR(vis,0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	d[1] = 0; vis[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int m = q.front();q.pop();
		for(int i = 0; i < (int)e[m].size(); i++) {

			int v = e[m][i];
			if(vis[v]) continue;
			d[v] = d[m] + 1;
			vis[v] = 1;
			q.push(v);
		}
	}
	std::vector<int> ve;
	for(int i = 1; i <= n; i++) {
		f[i] = d[i];
		ve.PB(i);
	}
	sort(all(ve),[](int u,int v){
		return d[u] > d[v];
	});
	for(auto u : ve) {
		f[u] = d[u];
		for(int i = 0; i < (int)e[u].size(); i++) {
			int v = e[u][i];
			if(d[v] > d[u]) {
				f[u] = min(f[u],f[v]);
			}else {
				f[u] = min(f[u],d[v]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << f[i] << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
}