#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	cin >> n;
	for(int i = n ;i >= 3; i--) {
		cout << i << " " << i-1 << "\n" ;
	}
	cout << 2 << " " << 3 << "\n";
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