#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
void solve() {
	cin >> n;
	int cnt[3] = {0};
	for(int i = 1; i <= n; i++) {
		cin >> m;
		cnt[m]++;
	}
	if((cnt[1] + 2 * cnt[2])%2 != 0) {
		cout << "NO" << "\n";
		return;
	}
	else {
		int p = (cnt[1] + 2 * cnt[2]) / 2;
		if(p % 2 != 0 && cnt[1] == 0) cout << "NO"<<"\n";
		else cout << "YES" << "\n";
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