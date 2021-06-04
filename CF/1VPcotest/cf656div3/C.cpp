#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	cin >> n;
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	// int flag = 0;
	// int cnt = 0;
	// for(int i = n-2; i > 0; i--) {
	// 	if(a[i] < a[i+1] && a[i] < a[i-1]) {
	// 		flag = 1;
	// 		cnt = i;
	// 	}
	// }
	// cout << cnt << "\n";
	int k = n;
	while(a[k-1] >= a[k] && k > 1) k--;
	while(a[k-1] <= a[k] && k > 1) k--;
	cout << k-1 << "\n";

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