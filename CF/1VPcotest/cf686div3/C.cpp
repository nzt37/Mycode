#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
int a[maxn], vis[maxn];
void solve()
{
	int n;
	cin >> n;
	int maxx = -1;
	memset(vis,0,sizeof(vis));
	for(int i =  1; i <= n ;i++) {
		cin >> a[i];
		vis[a[i]]++;
		if(a[i] == a[i-1]) {
			vis[a[i]]--;
		}
		if(i == 1) {
			vis[a[i]]--;
		}
		if(i == n) {
			vis[a[i]]--;
		}
		maxx = max(maxx,a[i]);
	}
	int minn = INT_MAX;
	for(int i = 1; i <= n; i++) {
		minn = min(minn,vis[a[i]]);
	}
	cout << minn+1 << "\n";
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