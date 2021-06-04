#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
#define int long long
int n,m;

void solve()
{
	int n;
	cin >> n;
	int _n = n;
	int cnt = 0,cnt_num = 0;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			
			int prime = 0;
			while(n%i == 0) { prime++,n /= i; }
			if(cnt_num < prime) {
				cnt = i;
				cnt_num = prime;
			}
		}
	}
	if(n > 1 && cnt_num < 1) {
		cnt = _n;
		cnt_num = 1;
	}
	cout << cnt_num << endl;
	for(int i = 1; i < cnt_num; i++) {
		cout << cnt << " ";
		_n /= cnt;
	}
	cout << _n << "\n";
	 
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