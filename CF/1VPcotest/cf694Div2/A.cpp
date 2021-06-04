#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 6;
int n,m;
int a[maxn];
void solve() {
	cin >> n >> m;
	int ans = 0,an = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		ans += a[i];
		an += (a[i] + m - 1) / m;
	}
	cout << (ans + m - 1) / m  << " " << an <<  "\n";
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