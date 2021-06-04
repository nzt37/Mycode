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
#define int long long
int n,m;
ll work(int a,int b,int x,int y,int n) {
	ll ans;
	if(a - x >= n) a -= n,n = 0;
	else n -= (a-x) ,a = x;
	if(b - y >= n) b -= n,n = 0;
	else n -= (b - y), b = y;
	return 1ll * a * b;
}
void solve() {
	int a,b,x,y;
	cin >> a >> b >> x >> y >> n;
	cout << min(work(a,b,x,y,n),work(b,a,y,x,n)) << "\n";

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