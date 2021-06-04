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
#define int long long
int n,m;
int a[maxn],w[maxn];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	sort(a+1,a+1+n);
	sort(w+1,w+1+m,[](int a,int b){
		return a > b;
	});
	ll ans = 0;
	int r = n;
	int l = 1;
	for(int i = m; i >= 1; i--) {
		if(w[i] == 1) {
			ans += a[r--] * 2;
		}
		else {
			break;
		}
	}
	for(int i = 1; i <= m; i++) {
		if(w[i] == 1) {
			break;
		}
		else {
			ans += a[r]+a[l];
			r--;
			l += w[i] - 1;
		}
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