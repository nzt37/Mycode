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
const int mod = 998244353 ;
int n,m;
int an[maxn];
void solve() {
	cin >> n;
	an[0] = 1;
	for(int i = 1; i <= n; i++) {
		an[i] = an[i-1] * 10 % mod;
	}
	for(int i = 1; i <= n; i++) {
		if(i == n) {
			cout << 10 << "\n";
		}
		else {
			int ans = ((18 * an[n-i])%mod + (n-i-1) * 81 * (an[n-i-1]) % mod) % mod;
			cout << ans << " \n"[i==n];
		}
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