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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn];
void solve() {
	cin >> n;
	bitset<100001> dp;
	int sum = 0;
	 dp.set(0);
	for(int i = 1; i <= n ;i ++) {
		cin >> a[i];
		sum += a[i];
		dp |= (dp << a[i]);
	}
	if((sum & 1) || (!dp[sum/2])) {
		cout << 0 << "\n";
		return ;
	}
	while(1) {
		for(int i = 1; i <= n; i++) {
			if(a[i] & 1) {
				cout << 1 << "\n" << i << "\n";
				return;
			}
		}
		for(int i = 1; i <= n; i++) {
			a[i] >>= 1;
		}
	}
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