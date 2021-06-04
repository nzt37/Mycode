#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cout <<i%n+1 << " ";
	}
	cout << "\n";
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