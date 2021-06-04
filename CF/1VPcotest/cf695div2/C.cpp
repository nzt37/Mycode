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
	int s;
	cin >> n >> m >> s;
	std::vector<int> a(n+1),b(m+1),c(s+1);
	int minn1 = INT_MAX,minn2 = INT_MAX,minn3 = INT_MAX;
	int maxx = -1; 
	int sum1 = 0,sum2 = 0,sum3 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		// if(minn < a[i]) {
		// 	minn = a[i];
		// }
		minn1 = min(minn1,a[i]);
		maxx = max(maxx,a[i]);
		sum1 += a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		minn2 = min(minn2,b[i]);
		maxx = max(maxx,b[i]);
		sum2 += b[i];
	}
	for(int i = 1; i <= s; i++) {
		cin >> c[i];
		minn3 = min(minn3,c[i]);
		maxx = max(maxx,c[i]);
		sum3 += c[i];
	}
	int ans = max(sum1+sum2-sum3,max(sum1+sum3-sum2,sum2+sum3-sum1));
	ans = max(ans,sum1+sum2+sum3-2*min(minn1+minn2,min(minn2+minn3,minn1+minn3)));
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
//