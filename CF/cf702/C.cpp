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
// #define mid ((r+l)>>1)
// #define lson p<<1,l,mid
// #define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
bool check(ll x) {
	ll l = 1;
	ll ans = -1;
	ll r = min(x,1ll*10000);
	while(l <= r) {
		ll mid = l + r >> 1;
		if(mid * mid * mid < x) {
			l = mid+1;
		}
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	return ans * ans * ans == x;
}
void solve() {
	ll a;
	cin >> a;
	for(ll i = 1; i <= a; i++) {
		if(1ll * i * i * i > a) break;
		ll j = a - i * i * i;
		if(check(j)) {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
	return;
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