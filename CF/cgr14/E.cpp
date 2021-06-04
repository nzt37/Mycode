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
const int maxn = 400 + 2;

ll dp[maxn][maxn],mul[maxn],inv[maxn],invf[maxn];
ll n,m,p,f[maxn];
ll C(ll n,ll m)
{
    if(m > n || m < 0 || n < 0) return 0;
    ll ans = f[n];
    ans = ans * invf[m] % p;
    ans = ans * invf[n-m] % p;
    return ans; 
}
void init() {
	f[0] = f[1] = 1,mul[1] = 1;
	inv[0] = invf[0] =  inv[1] = invf[1] = 1;
	for(int i = 2; i < maxn; i++) {
		f[i] = f[i-1] * i % p;
		inv[i] = (p - p/i) * inv[p % i] % p;
		invf[i] = invf[i-1] * inv[i] % p;;
		mul[i] = mul[i-1] * 2 % p;
	}
}
void solve() {
	cin >> n >> p;
	init();
	for(int i = 1; i <= n; i++) {
		dp[i][i] = mul[i];
		for(int j = 0; j <= i; j++) {
			for(int k = 1; i + k + 1 <= n; k++) {
				dp[i+1+k][j+k] = (dp[i+1+k][j+k] + dp[i][j]*mul[k]%p*C(j+k,k)%p)%p; 
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		ans = (ans + dp[n][i]) % p;
	}
	cout << ans << "\n";

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