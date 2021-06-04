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
const int maxn = 3e3 + 10;
int p[maxn][maxn];
int a[maxn];
int n,m;
void solve() {
	cin >> n;
	CLR(p,0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		for(int j = 1; j <= n; j++) {
			p[i][j] = p[i-1][j];
		}
		p[i][a[i]]++;
	}
	
	int ans = 0;
	for(int j = 2; j <= n; j++) {
		for(int k = j + 1; k < n; k++) {
			ans += p[j-1][a[k]] *(p[n][a[j]]-p[k][a[j]]);
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