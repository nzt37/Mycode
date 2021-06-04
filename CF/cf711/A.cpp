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
#define int long long
int f(int x) {
	int sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
void solve() {
	cin >> n;
	for(int i = n; ; i++) {
		if(__gcd(f(i),i) != 1) {
			cout << i << "\n";
			return;
		}
	}
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