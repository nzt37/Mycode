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
const int mod = 1e9 + 7;
int n,m;
ll f[2][222][222][2];
char a[maxn],b[maxn];
int main() {
	int k;
	cin >> n >> m >> k;
	cin >> a + 1;
	cin >> b + 1;
	int val = 1;
	f[1][0][0][0] = f[0][0][0][0] =  1;
	for(int i = 1; i <= n; i++,val^=1) {
		for(int j = 1; j <= m; j++) {
			for(int p = 1; p <= k; p++) {
				if(a[i] == b[j]) {
					(f[val][j][p][1] = ((f[val^1][j-1][p-1][1] + f[val^1][j-1][p-1][0])%mod + f[val^1][j-1][p][1])) %= mod;
					(f[val][j][p][0] = f[val^1][j][p][0] + f[val^1][j][p][1]) %= mod;  
				}
				else {
					f[val][j][p][1] = 0;
					(f[val][j][p][0] = f[val^1][j][p][0] + f[val^1][j][p][1]) %= mod;
				}
			}
		}
	}
	ll ans = 0;
	ans = (f[n&1][m][k][1] + f[n&1][m][k][0]) % mod;
	cout << ans << "\n";
	return 0;

}