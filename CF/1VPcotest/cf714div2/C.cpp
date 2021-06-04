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
const int mod = 1e9 + 7;
int n,m;
int dp[11][maxn];
int dfs(int a,int b) {
	if(dp[a][b] != -1) return dp[a][b];
	if(b == 0) return 1;
	int ret = 0;
	if(a <= 8) {
		ret += dfs(a+1,b-1);
	}
	else {
		ret += dfs(1,b-1) + dfs(0,b-1);
		ret %= mod;
	}
	dp[a][b] = ret;
	return ret ;
}
void solve() {
	cin >> n >> m;
	
	int ans = 0;
	while(n) {
		ans += dfs(n % 10,m);
		ans %= mod;
		n /= 10;
	}
	cout << ans % mod << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	CLR(dp,-1);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}