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
#define int long long
using namespace std;
const int inf = 1e15;
const int maxn = 2e5 + 10;
int n,m;
int a[maxn],b[maxn],c[maxn],a1[maxn];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	a[0] = 0,a1[0] = 0;
	for(int i = 1; i <= n; i++) {
		if(b[i] == 1) a[++a[0]] = a[i];
		else a1[++a1[0]] = a[i];
	}
	sort(a+1,a+1+a[0],[](int a,int b){
		return a > b;
	});
	sort(a1+1,a1+1+a1[0],[](int a,int b){
		return a > b;
	});
	for(int i = 1; i <= a1[0]; i++) {
		c[i] = c[i-1] + a1[i];
	}
	ll ans = inf;
	ll sum = 0;
	// for(int i = 1; i <= a[0]; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << "\n";
	for(int i = 1; i <= a[0]; i++) {
		sum += a[i];
		// cout << sum << "\n";
		if(sum >= m) {ans = min(ans,i);break;}
		int k = m - sum;
		int o = lower_bound(c + 1,c + 1 + a1[0],k)-c;
		if(o == a1[0] + 1) continue;
		ans = min(ans,i + o * 2);
	}
	int o = lower_bound(c + 1,c + 1 +a1[0],m)-c;
	if(o != a1[0]+1)
	ans = min(ans,o * 2);
	if(ans == inf) cout << -1 << "\n";
	else cout << ans << "\n"; 	
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