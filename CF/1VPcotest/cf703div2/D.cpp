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
int a[maxn];
bool check(int x){
	std::vector<int> f(n+1),sum(n+1),msum(n+1);
	for(int i = 1; i <= n; i++) {
		if(a[i] >= x) f[i] = 1;
		else f[i] = -1;
	}
	// sum[1] = f[1],msum[1] = sum[1];
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + f[i];
		msum[i] = min(msum[i-1],sum[i]);
	}
	int flag = 0;
	for(int i = m; i <= n; i++) {
		if(sum[i] - msum[i-m] >= 1 ) flag = 1;
	}
	return flag;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1,r =  n;
	int ans = -1;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			l = mid+1;
			ans = mid;
		}
		else {
			r = mid-1;
		}
	}
	cout << ans << "\n";
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