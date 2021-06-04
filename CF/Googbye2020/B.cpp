#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
int a[maxn];
void solve()
{
	cin >> n;
	std::vector<int> cnt(2 * n + 1);
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		x--;
		cnt[x]++;
	}
	int last = -1,ans = 0,sum = 0;
	for(int i = 0; i < 2 * n + 1 ; i++ ) {
		// int sum = cnt[i];
		if(cnt[i] > 0) {
			sum += cnt[i];
			ans++;
		}
		else {
			if(sum >= i - last) {
				ans++;

			}
			last = i;
			sum = 0;
		}
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
