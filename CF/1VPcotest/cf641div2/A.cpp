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
#define int long long 
const int maxn = 2e5 + 10;

int n,m;
void solve() {
	int k;
	cin >> n >> k;
	if(n & 1) {
		int an = 0;
		for(int i = 2; i <= n; i++) {
			if(n % i == 0) {
				an = i;
				break;
			}
		}
		cout << n + an + 2 * (k-1) << "\n";
	}
	else {
		cout  << n + (2 * k)<< "\n";
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