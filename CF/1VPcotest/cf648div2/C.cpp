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
int a[maxn],b[maxn];
int p[maxn];
int cnt[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		if(i <= p[b[i]]) {
			cnt[p[b[i]]-i]++;
		}
		else {
			cnt[n-i+p[b[i]]]++;
		}
		// ans = max(ans,p[b[i]])
	}
	for(int i = 0; i <= n; i++) {
		ans = max(ans,cnt[i]);
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