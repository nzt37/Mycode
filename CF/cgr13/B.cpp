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

const int maxn = 1e6 + 10;

int n,m;
int a[maxn];
void solve() {
	int u,v;
	cin >> n >> u >> v;;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int mx = -1;
	for(int i = 1; i < n; i++) {
		mx = max(mx,abs(a[i]-a[i+1]));
	}
	if(mx > 1) {
		cout << 0 << "\n";
	}
	else if(mx == 1){
		cout << min(u,v) << "\n";
	}
	else if(mx == 0) {
		cout << min(u + v, 2 * v) << "\n";
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