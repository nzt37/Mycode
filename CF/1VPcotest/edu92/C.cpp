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
	string s;
	cin >> s;
	int n = s.size();
	map<char,int> cnt;
	int ans = 0;
	for(char i:s) {
		cnt[i]++;
		ans = max(ans,cnt[i]);
	}
	ans = n - ans;
	// cout << ans << "\n";
	for(char i = '0'; i <= '9'; i++) {
		for(char j = '0'; j <= '9'; j++) {
			string c{i,j};
			int l = 0;
			for(char i : s) {
				if(c[l % 2] == i) {
					l++;
				}
			}
			if(l&1) l--;
			ans = min(ans,n-l);
		}
	}
	cout << ans << "\n";
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