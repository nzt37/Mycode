#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 6;
int n,m;
void solve() {
	int k;
	cin >> n >> m >> k;
	int ans = 1;
	while(n % 2 == 0) {
		n/=2;
		ans *= 2;
	}
	while(m % 2 == 0) {
		m/=2;
		ans *= 2;
	}
	
	if(ans >= k) {
		cout << "YES" << "\n";
	}
	else cout << "NO" << "\n";
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