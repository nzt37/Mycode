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
void solve() {
	cin >> n >> m;
	string s;
	cin >> s;
	int r = 0;
	int l = 0;
	std::vector<int> f(n,0x3f3f3f3f);
	for(int i = 0; i < n; i++) {
		if(s[i] == '*' ) {
			f[i] = 1;
			break;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = max(i - m,0); j <= i; j++) {
			if(s[i] == '*') {
				f[i] = min(f[i],f[j]+1);
			}
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '*') {
			cout << f[i] << "\n";
			return;
		}
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