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

int n,m;
void solve() {
	cin >> n >> m;
	if(n > m || (n & 1) != (m & 1)) {
		cout << -1 << "\n";
		return;
	}
	int p = m - n;
	if(!p) {
		if(!n) {
			cout << 0 << "\n";
		}
		else {
			cout << 1 << "\n" << n << "\n";
		}
	}
	else {
		if(((p / 2) & n) == 0) {
			cout << 2 << "\n";
			cout << p / 2 << " " << ((p / 2) ^ n) << "\n";
			return;
		}
		cout << 3 << "\n";
		cout << p / 2 << " " << p / 2 << " " << n << "\n";
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