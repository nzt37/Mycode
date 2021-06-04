#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
int a[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	std::vector<int> dp(n+1);
	for(int i = n; i >= 1; i--) {
		if(i + a[i] > n) dp[i] = a[i];
		else dp[i] = a[i] + dp[i+a[i]];
		ans = max(dp[i],ans);
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