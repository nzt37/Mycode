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
void solve() {
	int k;
	cin >> n >> m >> k;
	int ans = n + m - 2 + n * m-1;
	cout << ans << "\n";
	for(int i = 1; i < n; i++) {
		cout << "U";
	}
	for(int i = 1; i < m; i++) {
		cout << "L";
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < m; j++) {
			cout << (i & 1 ? 'R' : 'L');
		}
		if(i < n) cout << 'D';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}