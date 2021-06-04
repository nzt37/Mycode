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

const int maxn = 1e3 + 10;

int n,m;
int dp[maxn][maxn];
const int mod = 1e9 + 7;
void solve() {
	cin >> n >> m;
	CLR(dp,0);
	for(int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for(int i = 1;  i <= m; i++) {
		dp[0][i] = 1;
	}
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			dp[i][j] = (dp[n-i][j-1] + dp[i-1][j]) % mod;
		}
	}
	cout << dp[n][m] << "\n";
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