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
int a[maxn],s[maxn];
void solve() {
	int k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	a[n+1] = k+1;
	for(int i = 1; i <= n; i++) {
		s[i] = a[i+1] - a[i-1] - 2 + s[i-1];
		// s[i] = s[i-1] 
	}
	// int ans = 0;
	for(int i = 0; i < m ;i++) {
		int l,r;
		cin >> l >> r;
		if(l == r) { cout << k-1 << "\n"; }
		else {
			int ans = s[r-1]-s[l] + a[l+1] - 2 + k - a[r-1]-1;
			cout << ans << "\n";
		}
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
// 2 4 6  7
// 3 4 5   4 5 6   5 6 7  6 7 8  8 9 10 
// 