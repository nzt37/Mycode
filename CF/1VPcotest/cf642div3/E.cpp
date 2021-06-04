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
#define lson p<<1,l,midb
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
	string s;
	int k;
	cin >> n >> k;
	cin >> s;
	int ans = 0;
	int cnt = count(all(s),'1');
	for(int i = 0; i < k ;i++) {
		int an = 0,mi = 0;
		for(int j = i; j < s.size(); j += k) {
			an += s[j] == '1' ? 1 : -1;
			mi = min(mi,an);
			ans = max(ans,an - mi);
		}
	}
	cout << cnt - ans << "\n";
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