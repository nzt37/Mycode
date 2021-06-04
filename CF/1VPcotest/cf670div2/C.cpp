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
int out[maxn],sum[maxn],fa[maxn],mm[maxn];
int minn;
std::vector<int> e[maxn];
void dfs(int u,int fat) {
	sum[u] = 1,fa[u] = fat;
	for(int i = 0; i < (int)e[u].size(); i++) {
		int v = e[u][i];
		if(v != fat) {
			dfs(v,u);
			sum[u] += sum[v];
		}
	}
	for(int i = 0; i < (int)e[u].size(); i++) {
		int v = e[u][i];
		if(v != fat) {
			mm[u] = max(mm[u],sum[v]);
		}
	}
	mm[u] = max(mm[u],n-1-sum[u]);
	minn = min(minn,mm[u]);
}
void solve() {
	cin >> n;
	minn = n + 10;
	for(int i = 1; i <= n; i++) {
		e[i].clear();
	}
	for(int i = 0; i <= n; i++) {
		fa[i] = sum[i] = out[i] = mm[i] = 0;
	}
	for(int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].PB(v);
		e[v].PB(u);
		out[u]++;
		out[v]++; 
	}
	int x,y;
	for(int i = 1; i <= n; i++) {
		if(out[i] == 1) {
			x = i; y = e[i][0];
			e[x].erase(find(e[x].begin(),e[x].end(),y));
			e[y].erase(find(e[y].begin(),e[y].end(),x));
			break;
		}
	}
	dfs(x == 1 ? 2 : 1,0);
	for(int i = 1; i <= n; i++) {
		if(mm[i] == minn) {
			cout <<x<<" "<<y<<"\n"<<x<<" "<<i<<"\n";
			return;
		}
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