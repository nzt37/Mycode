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
int calc(int n) {
	int ans = 0;
	while(n) ans += n % 10,n /= 10;
	return ans;
}
void solve() {
	int s;
	cin >> n >> s;
	if(calc(n) <= s) {
		cout << 0 << "\n";
		return;
	}
	int cnt = 0;
	int _n = n;
	while(_n) cnt ++ ,_n /= 10;
	int k = 1;
	for(int i = 1; i <= cnt; i++) {
		k *= 10;
		if(calc(k - n % k + n) <= s) {
			cout << k - n % k << "\n";
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