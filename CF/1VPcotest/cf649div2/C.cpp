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
const int maxn = 1e6 + 10;

int a[maxn];
int n,m;
int vis[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]]++;
	}
	std::vector<int> v;
	for(int i = 0; i <= 1e6; i++) {
		if(!vis[i]) {
			v.PB(i);
		}
	}
	int cnt = 0;
	std::vector<int> b(n+1);
	for(int i = 1; i <= n; i++) {
		if(i == 1 || a[i] == a[i-1]) {
			b[i] = v[cnt++];
		}
		else {
			b[i] = a[i-1];
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << b[i] << " \n"[i==n];
	}
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