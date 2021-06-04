#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
int a[maxn],b[maxn],c[maxn],d[maxn];
void solve()
{
	cin >> n;
	// std::vector<int> a(n),b(m),c[n+m];
	int ans1 = 0,ans2 = 0;
	for(int i = 0; i <= n + m; i++) {
		c[i] = b[i] = 0;
	}
	for(int i = 1 ; i <= n; i++) {
		cin >> a[i];
		c[i] = c[i-1] + a[i];
		// cout << c[i] << " dfs" << "\n";
		ans1 = max(ans1,max(0,c[i]));
	}
	cin >> m;
	for(int i = 0; i < m; i++) {

		cin >> b[i];
		d[i] = d[i-1] + b[i];
		ans2 = max(ans2,(0,d[i]));
	}
	
	cout << ans1 + ans2 <<  "\n";

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