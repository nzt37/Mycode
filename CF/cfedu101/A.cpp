#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	string s;
	// cin >> n;
	cin >> s;
	if(s.size() % 2 == 0 && (s[0]!=')' && s[s.size() - 1] != '(')) {
		cout << "YES" << "\n";
	}
	else cout << "NO" << "\n";
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