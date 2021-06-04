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
std::vector<int> d[maxn];
int a[maxn],vis[maxn],c[maxn],cnt[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		//cnt[i] = a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		vis[i] = 0;
	}
	int ans = n + 1;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			int m = i;
			std::vector<int> v;
			while(!vis[m]) {
				v.PB(c[m]);
				// 1 7 3 5 1
				cout << c[m] << " ";
				vis[m] = 1;
				m = a[m];
			}
			m = v.size();
			// cout << i << " dsds " << m;
			for(auto k : d[m]) {
				// cout << k << " ";
				for(int j = 0; j < k; j ++) {
					bool f = 1;
					for(int o = j; o < m; o+=k) {
						f &= v[o] == v[j];
					}
					if(f) {
						// cout << i << j << k << " ccs \n";
						ans = min(ans,k);
					}
				}
			}
			cout << "\n";
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for(int i = 1; i <= 200000; i++) {
		for(int j = i; j <= 200000; j+=i) {
			d[j].PB(i);
		}
	}
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}