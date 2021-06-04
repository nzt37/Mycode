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
int a[maxn],b[maxn];
int sum1[maxn],sum2[maxn],min1[maxn],min2[maxn];
void solve() {
	cin >> n;
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(i & 1) {
			a[++cnt1] = x;
		}
		else {
			b[++cnt2] = x;
		}
	}
	min1[0] = 1e9;
	min2[0] =  1e9;
	for(int i = 1; i <= cnt1; i++) {
		sum1[i] = sum1[i-1] + a[i];
		min1[i] = min(min1[i-1],a[i]); 
	}
	for(int i = 1; i <= cnt2; i++) {
		sum2[i] = sum2[i-1] + b[i];
		min2[i] = min(min2[i-1],b[i]); 
	}
	int ans = 1e18;
	for(int i = 1; i <= min(cnt1,cnt2); i++) {
		ans = min(ans,1ll*(n-i)*min1[i]+sum1[i]+1ll*(n-i)*min2[i]+sum2[i]);
	}
	for(int i = 2; i <= cnt1; i++)
	{
		ans = min(ans,  1ll*(n - i) * min1[i] + sum1[i] +  1ll*(n - i + 1) * min2[i - 1] + sum2[i - 1]);
	}
	// cerr << ans << "\n";
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