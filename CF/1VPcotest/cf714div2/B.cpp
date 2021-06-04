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
int a[maxn];
void solve() {
	cin >> n;
	int an = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		an = (i == 1 ? a[i] : a[i] & an);
	}
	int cnt = count(a+1,a+1+n,an);
	int ans = (cnt * (cnt - 1)) % mod;
	for(int i = 2; i <= n-2; i++) {
		ans = ans * i % mod;
	}
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}