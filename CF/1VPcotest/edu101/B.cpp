#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
int a[maxn],b[maxn],c[maxn];
void solve()
{
	cin >> n;
	int max1 = 0,max2 = 0;
	int ans1 = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ans1 += a[i];
		max1 = max(ans1,max1);
	}
	ans1 = 0;
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		ans1 += b[i];
		max2 = max(max2,ans1);
	}
	cout << max1 + max2 << "\n";
	//return;
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