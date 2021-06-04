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
const int maxn = 1000010;

int n,m;
#define int long  long
int a[maxn],b[maxn],c[maxn],ans[maxn];
std::vector<bool> v(maxn+1,0);
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	v[0] = 1;
	for(int i = 1; i <= n; i++) {
		auto d = v;
		for(int j = 0; j <= m; j++) {
			if(!v[j]) continue;
			if(j == 0 && a[i] == 2) continue;
			int p = j;
			for(int k = 1; k <= c[i]; k++) {
				if(a[i] == 1) {
					p = p + (b[i] + 100000 - 1)/100000;
					
				}
				else {
					p = (p * b[i] + 100000 - 1)/100000;
				}
				if(p > m || v[p]) break;
				ans[p] = i;
				d[p] = 1;
			}
		}
		v = d;
	}
	for(int i = 1; i <= m; i++) {
		cout << (ans[i] ? ans[i] : -1) << " \n"[i == m];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}