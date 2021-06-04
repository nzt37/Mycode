#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 6;
int n,m;
int a[maxn],cnt[maxn];
void solve() {
	cin >> n >> m;
	std::vector<int> b;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		// int c;
		cin >> a[i];
		ans += a[i];
		cnt[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		int c = a[i];
		while(c % m == 0) {
			c /= m;
			cnt[i]++;
		}
	}
	while(1) {
		for(int i = 1; i <= n; i++) {
			if(cnt[i]) cnt[i]--,ans += a[i];
			else {
				cout << ans << "\n";
				return;
			}
		}
	}
}
signed main() {
 	ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
    	solve();
    }   
    return 0;
}