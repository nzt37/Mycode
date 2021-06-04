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
int a[maxn];
void solve() {
	int k;
	cin >> n >> k;
	map<int,int> mp;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
	}
	sort(a+1,a+1+n);
	for(int i = 1,j; i <= n; i = j) {
		for(j = i; j <= n && a[i] == a[j]; j++);
		// cout << j << "\n";
		if(a[i] == 0) continue;
		ans = max(ans,k-a[i]+(j-i-1)*k+1);
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