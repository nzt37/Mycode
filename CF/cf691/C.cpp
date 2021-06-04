#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
#define int long long
int n,m;
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a%b);
}
void solve()
{
	cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> b(m);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n-1; i++) {
		ans = gcd(ans,a[i+1] - a[i]);
	}
	for(int i = 0; i < m; i++) {
		cout << abs(gcd(ans,a[0] + b[i])) << " \n"[i == m - 1];
	}
	
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int T = 1;
	// cin >> T;
    while(T--) {
 		solve();   	
    }
    return 0;
}