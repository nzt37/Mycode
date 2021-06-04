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
int p[maxn],ip[maxn],cnt,c[maxn];
std::vector<int> v[maxn];
void init(int n) {
	for(int i = 2; i <= n; i++) {
		if(!ip[i]) p[++cnt] = i;
		for(int j = i+i; j <= n; j += i) {
			ip[j] = 1;
		}
	}
	for(int i = 1; i <= cnt; i++) {
		for(int j = p[i]; j <= n; j += p[i]) {
			v[j].push_back(i);
		}
	}
}
int nxt[maxn][21],a[maxn];
void solve() {
	init(100000);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = 0;
	for(int i = 1; i <= n; i++) {
		
		if(i != 1) {
			for(int j : v[a[i-1]]) {
				c[j]--;
			}
		}
		while(k <= n) {
			k++;
			if(k == n + 1) break;
			for(auto j : v[a[k]]) c[j]++;
			int flag = 0;
			for(auto j : v[a[k]]) {
				if(c[j] == 2) {
					flag = 1;
				}
			}
			if(flag) {
				for(auto j : v[a[k]]) {
					c[j]--;
				}
				break;
			}
		}
		nxt[i][0] = k,k--;
	}
	nxt[n+1][0] = n + 1;
	for(int k = 1; k <= 20; k++) {
		nxt[n+1][k] = n+1;
		for(int i = 1; i <= n; i++) {
			nxt[i][k] = nxt[nxt[i][k-1]][k-1];
		}
	}
	 for(int i = 1; i <= n; i++) {
	 	for(int j = 0; j <= 3; j++) {
	 		cout << nxt[i][j] << " \n"[j == 3];
	 	}
	 }
	while(m--) {
		int l,r;
		cin >> l >> r;
		int ans = 0 ;
		for(int k = 20; k >= 0; k--) {
			if(nxt[l][k] <= r) {
				cout << nxt[l][r] << " " << k << "\n";
				ans += (1 << k);
				l = nxt[l][k];
			}
		}
		cout << ans+1 << "\n";
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