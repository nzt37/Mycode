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
int a[maxn],cnt[maxn];
void solve() {
	cin >> n >> m;
	CLR(cnt,0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]%m]++;
	}
	int ans = 0;
	ans += (cnt[0] ? 1 : 0);
	if(m % 2 == 0 && cnt[m/2]) {
		ans++;
	}
	for(int i = 1; i < (m+1)/2; i++) {
		if(cnt[i] || cnt[m-i]) {
			int l = max(cnt[i],cnt[m-i]);
			int r = min(cnt[i],cnt[m-i]);
			int x = l - r;
			if(x <= 1) {
				ans += 1;
			}
			else {
				ans += x;
			}
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