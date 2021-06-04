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
ll f[10][512][100];
int t[maxn],num[maxn];
int cnt;
void init() {
	cnt = 0;
	for(int i = 0; i < (1<<n); i++) {
		if(i&(i<<1)) continue;
		int sum = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1<<j)) sum++;
		}	
		t[++cnt] = i;
		num[cnt] = sum;
	}
}
int main() {
	// cout << (1<<9) << "\n";
	int p;
	cin >> n >> p;
	init();	
	// f[0][1][0] = 1;
	for(int i = 1; i <= cnt; i++) {
		f[1][i][num[i]] = 1;
	}
	// cout << cnt << "\n";
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= cnt; j++) {
			for(int k = 1; k <= cnt; k++) {
				if(t[j] & t[k]) continue;
				if((t[j]<<1) & t[k] ) continue;
				if(t[j]&(t[k]<<1)) continue;
				for(int o = p; o >= num[j]; o--) {
					f[i][j][o] += f[i-1][k][o-num[j]];
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= cnt; i++) {
		ans += f[n][i][p];
	}
	cout << ans << "\n";
	return 0;
}