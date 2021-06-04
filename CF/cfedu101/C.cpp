#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	int k;
	cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin << a[i];
	}
	std::vector<int> dp(n);
	dp[1] = a[0] - 1;
	for(int i = 2; i < n; i++) {
		dp[i] = dp[i] - 1;
		if(dp[i-1] + k - 1 < d[i]) {
			flag = 1;
			break;
		}
	}
	if(falg) {
		cout << "NO" << "\n";

	}
	else {
		cout << "NO" << "\n";
	}
	queue<int> a;
	while(!a.empty()) {
		int x = a.front();
		a.pop();
		for(int i = head[i]; i ; i = edge[i].next)
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