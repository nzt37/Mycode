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
int a[maxn];
int f[maxn],g[maxn];
const int inf = 0x3f3f3f3f;
void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	CLR(f,inf);
	CLR(g,inf);
	f[1] = a[1],f[2] = a[1]+a[2],g[1] = a[1],g[2]=a[1];
	for(int i = 3; i <= n; i++) {
		f[i] = min(g[i-1]+a[i],g[i-2]+a[i-1]+a[i-2]);
		g[i] = min(f[i-1],f[i-2]);
	}	
	cout << min(f[n],g[n]) << "\n";
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