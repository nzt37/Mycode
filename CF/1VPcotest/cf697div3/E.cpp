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
const int maxn = 2e4 + 10;
const int mod = 1e9+7;
int f[maxn],inc[maxn];
int n,m;
ll qpow(ll a,ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res % mod;
}
ll c(int n,int m) {
	if(n < m) return 0;
	return f[n] *inc[m] % mod * inc[n-m] % mod;
}
void init(int n) {
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		f[i] = (i * f[i-1]) % mod;
	}
	// inc[n] = qpow(f[n],mod-2);
	// for(int i = n; i >= 1; i--) {
	// 	inc[i-1] = inc[i] * i % mod; 
	// }
}
void solve() {
	int k;
	cin >> n >> k;
	std::map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		mp[a]++;
	}
	auto it = mp.rbegin();
	while(it != mp.rend()) {
		if(k > it->second) {
			k -= it->second;
			it++;
		} else {
			cout << c(it->second,k) % mod << "\n";
			return;
		}
	}
	// cout  << it->first << " " << it->second << '\n';

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	init(1050);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}