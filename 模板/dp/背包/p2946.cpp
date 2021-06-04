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
const int mod = 1e8;
int n,m;
int a[maxn];
long long f[2020][2020];
int sum[maxn];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		// sum[i] = (sum[i-1] + a[i]);
		f[i][a[i] % m] = 1;
		a[i] %= m;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			(f[i][j] += f[i-1][j] + f[i-1][((j-(a[i])+m)%m)]) %= mod; ;
		}
	}
	cout << f[n][0]%mod << "\n";
	// cout << ans << "\n";
	return 0;
}