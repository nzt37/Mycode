#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m;

const int maxn = 1e5 + 5;
int a[maxn],w[maxn];
signed main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		int k;
		cin >> w[i];
		k = w[i];
		for(int j = 1; j <= k; j++) {
			cin >> b[i][j];
		}
	}
	int num = 1;
	std::vector<int> ans;
	while(ans.){
		for(int j = 1; j <= m; j++) {
			int f = 1;
			if(vis[j]) continue;
			for(int k = 1; k <= w[j]; k++) {
				if(b[i][k] == a[num]) {
					num++;
				}
				else {
					f = 0;
					break;
				}
				if(f) {ans.push(j);
					vis[j] = 1;}
			}
		}
	}
}