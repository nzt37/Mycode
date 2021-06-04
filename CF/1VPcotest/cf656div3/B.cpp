#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	cin >> n;
	map<int,int> a;
	for(int i = 1; i <= n*2; i++) {
		cin >> m;
		if(!a[m]) {
			cout << m << " ";
			a[m]++;
		}
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