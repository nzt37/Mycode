#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m;

const int maxn = 1e5 + 5;
string s[maxn];
struct node{
	int x;
	std::vector<int> a;
}p[maxn];
signed main() {
	   	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	map<vector<int>,int> mp;
	for(int i = 1; i <= n; i++) {
		std::vector<int> b;
		for(int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		mp[b]++;
	}
	cout << mp.size() << "\n";
	int num = 0;
	for(auto i : mp) {
		num++;
		p[num].x = i.second;
		for(auto j : i.first) {
			p[num].a.push_back(j);
		}
	}
	sort(p+1,p+num+1,[](node l,node r){
		// int a,int b;
		if(l.x != r.x) return l.x > r.x;
		else {
			int n1 = l.a.size();
			int n2 = r.a.size();
			for(int i = 0; i < min(n1,n2); i++) {
				if(l.a[i] != r.a[i])
				return l.a[i] < r.a[i];
			}
			return n1 > n2;
		}
		
	});
	for(int i = 1; i <= num; i++) {
		cout << p[i].x << " ";
		for(int j = 0; j < p[i].a.size() - 1; j++) {
			cout << p[i].a[j] << " ";
		}
		cout << p[i].a[ p[i].a.size()-1];
		cout << "\n";
	}
	return 0;
}