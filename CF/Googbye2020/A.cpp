#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;

void solve()
{
	cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> b;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			b.insert(a[j] - a[i]);
		}
	}
	cout << b.size() << "\n";
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