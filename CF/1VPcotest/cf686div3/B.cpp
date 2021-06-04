#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
int cnt[maxn],a[maxn];
void solve()
{
	cin >> n;
	int maxx  = -1;
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		cnt[m] ++ ;
		a[m] = i;
		maxx=  max(m,maxx);
	}
	for(int i = 1; i <= maxx; i++) {
		if(cnt[i] == 1) {
			cout << a[i] << "\n";
			return;
		}
	}
	cout << -1 << "\n";
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