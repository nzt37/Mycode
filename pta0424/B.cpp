#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m;

const int maxn = 1e5 + 5;
string s[maxn];
	stack<char> an;
	std::vector<char> ans;

signed main() {
	int k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	int a;
	while(cin >> a) {
		if(a == -1) break;
		if(a == 0) {
			if(!an.empty())
			{
				ans.push_back(an.top());
				an.pop();
			}
			continue;

		}
		if(a != 0) {
			if((int)an.size()  == k) {
					ans.push_back(an.top());
					an.pop();
				
			}
			if(!s[a].empty()) {
				an.push(s[a][0]);
				s[a].erase(s[a].begin());

			}
			
		}
	}
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	return 0;
}