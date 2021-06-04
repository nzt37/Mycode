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
const int maxn = 5e5 + 10;
int n,m;
std::vector<int> e[maxn];
int in[maxn],ans[maxn];
void solve() {
	cin >> n;
	int mx = -1;
	for(int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].PB(i);
		e[v].PB(i);
		in[u]++;
		in[v]++;
	}
	for(int i = 1; i <= n; i++) {
		mx = max(mx,in[i]);
	}
	int cnt = 0;
	if(mx < 3) {
		for(int i = 0; i < n - 1; i++) {
			cout << i << "\n";
		}
		return;
	}
	else {
		for(int i = 1; i <= n; i++) {
			if(in[i] >= 3) {
				for(int j = 0; j < 3; j++) {
					ans[e[i][j]] = ++cnt;
				}
				break;
			}
		}
		for(int i = 1; i < n; i++) {
			if(ans[i]) continue;
			ans[i] = ++cnt;
		}
		for(int i = 1; i < n; i++) {
			cout << ans[i]-1 << "\n";
		}
		return;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}