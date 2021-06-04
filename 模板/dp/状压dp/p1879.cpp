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

const int maxn = 2e4 + 10;
const int mod = 100000000;
int n,m;
int f[15][1<<12+4],F[maxn];
int t[maxn],num[maxn];
int mp[20][20];
int g[maxn];

int main() {
	cin >> m >> n;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> mp[i][j];
			F[i] = (F[i] << 1) + mp[i][j];
		}
	}	
	f[0][0] = 1;
	for(int i = 0; i < (1<<n); i++) {
		g[i] = (!(i&(i<<1)) && (!(i & (i>>1))));
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j <= (1<<n); j++) {
			if(g[j] && (j & F[i]) == j)
			for(int k = 0; k <= (1<<n); k++) {
				if(k & j) continue;
				f[i][j] = (f[i][j] + f[i-1][k]) % mod;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <(1<<n); i++) {
		ans = (f[m][i] + ans) % mod;
	}
	cout << ans << "\n";
	return 0;
}