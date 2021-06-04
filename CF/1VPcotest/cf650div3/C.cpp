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
	int k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = " " + s;
	int ans = 0;
	int last = 0,next = 1;
	int flag = 0;
	std::vector<int> a(n+1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			a[++cnt] = i;
			flag = 1;
		}
	}
	for(int i = 1; i <= n ; i++) {
		if(i == a[next]) {
			next++;
			last = i;
			continue;
		}
		if(last == 0 || i - last > k) {
			if(next > cnt || a[next] - i > k) {
				ans++;
				last = i;
			}
		}
	}
	if(flag == 0 && ans == 0) cout << 1 << "\n";
	else
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