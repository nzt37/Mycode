#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3e5 + 6;
int n,m;
int c[maxn],k[maxn];
void solve() {
	memset(c,0,sizeof(c));
	memset(k,0,sizeof(k));
	cin >> n >> m ;
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
	} 
	for(int i = 1; i <= m; i++) {
		cin >> c[i];
	}
	int ans = 0,cnt = 1;
	sort(k+1,k+1+n);
	for(int i = n; i >= 1; i--) {
		if(cnt <= k[i]) {
			ans += c[cnt];
			cnt++;
		}
		else {
			ans += c[k[i]];
		}
	}
	cout << ans << "\n";
	return;
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