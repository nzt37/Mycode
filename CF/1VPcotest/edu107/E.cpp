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

const int maxn = 3e5 + 10;
const int mod = 998244353;
int n,m;
string s[maxn];
ll p[maxn];
ll f[maxn];
int main() {
	cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			// cin >> s[i][j];
			if(s[i][j] == 'o') sum++;
		}
	}
	p[0] = 1;
	for(int i = 1; i <= n * m; i++) {
		p[i] = p[i-1] * 2 % mod;
	}
	int len = max(n,m);
	for(int i = 2; i <= len; i++)  {
		f[i] = (f[i-1] + 2ll * f[i-2] + p[i-2]) % mod;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(int j = 0; j < m; j++) {
			if(s[i][j] == 'o') {
				cnt++;
			}
			if(s[i][j] == '*' || j == m-1) {
				ans = (ans + f[cnt] * p[sum-cnt]) % mod;
				cnt = 0;
			}
		}
	}
	for(int i = 0; i < m; i++) {
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			if(s[j][i] == 'o') {
				cnt++;
			}
			if(s[j][i] == '*' || j == n-1) {
				ans = (ans + f[cnt] * p[sum-cnt]) % mod;
				cnt = 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}