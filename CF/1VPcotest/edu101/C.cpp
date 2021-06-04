#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
int n,m;
int h[maxn];
void solve()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int minn = INT_MAX;
	int maxx = -1;
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			minn = h[0];
			maxx = h[0] + m;
		}
		else {
			minn = max(h[i],minn+1-m);
			maxx = min(h[i]+m-1,maxx + m - 1);
		}
		if(minn > maxx || minn > h[i] + m - 1 || maxx - m < h[i]) {
			cout << "NO" << "\n";
			return;
		}
	}
	if(minn != h[n-1]) {
		cout << "NO" << "\n";
	}
	else
	cout << "YES" << "\n";
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