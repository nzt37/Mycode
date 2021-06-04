#include <bits/stdc++.h>

using namespace std;
int n,m;
const int maxn = 1e4 + 5;
int p;
int a[maxn][maxn];
int vis[maxn];
std::vector<int> an;
std::vector<int> ans;
void dfs(int x) {
	
		if(an.size() > ans.size()) {
			ans = an;
		}
	for(int i = 0; i < n; i++) {
		if(a[x][i] && !vis[i]) {
			p++;
			vis[i] = 1;
			// cout << x << " " <<  i << " cs\n";
			an.push_back(i);
			dfs(i);
			an.pop_back();
			vis[i] = 0;
		}
	}
}
int main() {
    	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int b;
			cin >> b;
			a[i][b]++;
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int i = 0; i < n; i++) vis[i] = 0;
		vis[i] = 1;
		p = 0;
		an.clear();
		an.push_back(i);
		dfs(i);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << " ";
	}
	cout << ans[ans.size()-1] << "\n";
	return 0;
}