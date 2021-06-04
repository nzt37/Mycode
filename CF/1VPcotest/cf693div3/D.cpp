#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 6;
int n,m;
int a[maxn];
bool cmp(int a,int b) {return (a > b ? true : false);}
void solve() {
	cin >> n;
	for(int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	int ans = 0;
	sort(a+1,a+1+n,cmp);
	for(int i = 1; i <=  n; i++) {
		if(i & 1) {
			if(a[i] % 2 == 0) {
				ans += a[i];
			}
		}
		else {
			if(a[i]&1) {
				ans -= a[i];
			}
		}
	}
	if(ans == 0) cout << "Tie\n";
	else if(ans > 0) cout << "Alice\n";
	else cout << "Bob\n";

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