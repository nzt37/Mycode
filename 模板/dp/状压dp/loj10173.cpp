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
int mp[105][15];
int f[101][101][(1<<10)+5];
int a[maxn],h[maxn],num[maxn];
int cnt = 0;
int getsum(int n) {
	int sum = 0;
	while(n) {
		if(n & 1) {
			sum++;
		}
		n >>= 1;
	}
	return sum;
}
void init() {
	for(int i = 0; i < (1<<m); i++) {
		if( (i & (i << 1) || ( i & (i << 2) || ( i & (i >> 1) || (i &  (i >> 2)))))) continue;
		h[++cnt] = i;
		// for(int j = 0; j <= (1<<j); j++) {
		// 	num[cnt] += !!(i & (1 << j));
		// }
		num[cnt] = getsum(i);
		// cout << num[cnt] << "\n";
		if((i&a[1]) == i) f[1][0][cnt] = num[cnt];
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char s;
			cin >> s;
			if(s == 'P') {
				mp[i][j] = 1;
			}
			a[i] = (a[i] << 1) + mp[i][j];
		}
	}
	// f[0][0] = 1;
	init();
	// cout << cnt << "\n";
	for(int i = 1; i <= cnt ; i++) {
		for(int j = 1; j <= cnt; j++) {
			if(!(h[i] & h[j]) && (a[2] & h[j]) == h[j]) {
				f[2][i][j] = f[1][0][i] + num[j];
			}
		}
	}
	// for(int i = 1; i <= cnt; i++) {
	// 	// cout << h[i] << " " << num[i] << "\n";
	// 	cout << f[2][1][i] << "\n";
	// }
	for(int i = 3; i <= n; i++) {
		for(int j = 1; j <= cnt; j++) {
			if((a[i] & h[j]) == h[j]) {
				for(int k = 1; k <= cnt; k++) {
					if( !(h[j] & h[k])) {
						for(int l = 1; l <= cnt; l++) {
							if(!(h[l] & h[k]) && !(h[l] & h[j])) {
								f[i][k][j] = max(f[i][k][j],f[i-1][l][k] + num[j]); 
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++) {
		for(int j = 1; j <= cnt; j++) {
			// cout << f[n][i][j] << " ";
			ans = max(ans,f[n][i][j]);
		}
		// cout << "\n";
	}
	cout << ans << "\n";
	return 0;
}