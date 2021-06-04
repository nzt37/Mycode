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
const int mod = 9999973;
int n,m;
// int f[101][1<<101];
int f[200][200][200];
int C(int n) {
	return (n*(n-1))/2;
}
signed main() {
	cin >> n >> m;
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= m-j; k++) {
				f[i][j][k] = f[i-1][j][k];
				if(k>=1) f[i][j][k] = (f[i][j][k] + f[i-1][j+1][k-1] * (j+1)) % mod;
				if(j>=1) f[i][j][k] = (f[i][j][k] + f[i-1][j-1][k] * (m-j+1-k)) % mod;
				if(k>=2) f[i][j][k] = (f[i][j][k] + f[i-1][j+2][k-2] * (((j+2)*(j+1)/2)))%mod;
				// if(k>=1) f[i][j][k] = (f[i][j][k] + f[i-1][j][k-1] *  (m-j-k-1)) % mod;
				if(k>=1) f[i][j][k] = (f[i][j][k] + f[i-1][j][k-1] * j *  (m-j-k+1)) % mod;
				if(j>=2) f[i][j][k] = (f[i][j][k] + f[i-1][j-2][k] * (C(m-(j-2)-k))) % mod;
				f[i][j][k] %= mod;

			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= m; j++) {
			(ans += f[n][i][j]) %= mod;
		}
	}
	cout << ans%mod << "\n";
	return 0;
}