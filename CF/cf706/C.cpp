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
const int maxn = 1e5 + 10;

ll n,m,a[maxn],b[maxn];
void solve() {
	cin >> n;
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;  i < n + n; i++) {
		int x,y;
		cin >> x >> y;
		if(x == 0) a[cnt1++] =1ll* y * y;
		else b[cnt2++] =1ll* x * x;
	}
	sort(a,a+n);
	sort(b,b+n);
	double ans = 0;
	for(int i = 0; i < n; i++) {
		ans += sqrt(1ll*(a[i] + b[i]));
	}
	printf("%.12f\n", ans);
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}