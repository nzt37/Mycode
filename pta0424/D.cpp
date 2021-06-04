#include <bits/stdc++.h>

using namespace std;
int n,m;

const int maxn = 1e5 + 5;
std::vector<int> a[maxn];
int main() {
	cin >> n  >> m;
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i].push_back(0);
		for(int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	//cin >> m;
	int an = 1;
	std::vector<int> mp(101);
	for(int i = 1; i <= m; i++){
		int x,y;
		cin >> x >> y;
		if(x == 0) {
			an = a[an][y];
		}
		else if(x == 1) {
			mp[y] = an;
			cout << an << "\n";
		}
		else if(x == 2) {
			an = mp[y];
		}
	}
	cout << an << "\n";
}