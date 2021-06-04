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
int a[100][100];
int b[100],c[100];
void solve() {
	cin >> n >> m;
	int ans = 0;
	CLR(b,0);
	CLR(c,0);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) {
				// if(b[i] && c[j]) {
				// 	continue;
				// }
				// else if(b[i] || c[j]) {
				// 	ans += 1;
				// }
				// else 
				// ans += 2;
				b[i]++;c[j]++;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
		if(!b[i] && !c[j]) {
			ans++;
			b[i]++;c[j]++;
		} 
	}
	// cout << ans << "\n";
	// ans = n * m- ans;
	if(ans & 1) {
		cout << "Ashish" << "\n";
	}
	else {
		cout << "Vivek" << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}