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
int mp[330][330];
void solve() {
	cin >> n >> m;
	CLR(mp,0);
	if(m % n== 0) {
		cout << 0 << "\n";
	}
	else {
		cout << 2 << "\n"; 
	}
	int x = 1,y = 1;
	for(int i = 1; i <= m; i++) {
		mp[x][y] = 1;
		x++,y++;
		if(x == n + 1) {
			x = 1;
		}
		if(y == n + 1) {
			y = 1;
			x++;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n;j++) {
			cout << mp[i][j];
		}
		cout << "\n";
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