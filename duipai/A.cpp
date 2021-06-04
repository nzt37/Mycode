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
		cin >> a[i];
	}
	int h1 = abs(a[0] - a[1]);
	int h2 = abs(a[n-1] - a[n-2]);

	for(int i = 1; i < n - 1 ; i++) {
		if(h1 > abs(a[i] - a[i-1]) || abs(a[i] - a[i-1])  < h2) {
			cout << "NO" << "\n";
			return;
		}
	}
	for(int i = 0; i < n; i++) {
		if(a[i] + k - 1  < h1 || a[i] + k - 1 < h2 ) {
			cout << "NO" << "\n";
			return;
		}
	}
	cout << "YES" << "\n";
	return;

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