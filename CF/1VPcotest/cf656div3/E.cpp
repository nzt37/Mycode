#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
int f[maxn],in[maxn],vis[maxn],cnt,topo[maxn],tot;
std::vector<int> e[maxn],h[maxn];
std::vector<pair<int,int> > a;
bool topoo()
{
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(in[i] == 0) {
			q.push(i),cnt++;
		}
	}
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		topo[x] = ++tot;
		for(int i = 0; i < (int)e[x].size(); i++) {
			in[e[x][i]]--;
			//cout << e[x][i] << " ds" <<" \n";
			if(in[e[x][i]] == 0) {
				q.push(e[x][i]);
			}
		}
	}
	if(tot < n) return false;
	return true;
}
void solve()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		e[i].clear();
		in[i] = 0;
		topo[i] = 0; 
	}
	cnt = 0,tot = 0;
	a.clear();
	for(int i = 1; i <= m; i++) {
		int t,u,v;
		cin >> t >> u >> v;
		if(t == 1) {
			e[u].push_back(v);
			in[v]++;
		}
		else {
			a.push_back(make_pair(u,v));
		}
	}
	
	if(!topoo()) {
		cout << "NO" << "\n";
		return;
	}
	cout << "YES" << "\n";
	for(int i = 1; i <= n; i++) {
		for(auto v : e[i]) {
			cout << i << " " << v << "\n";
		}
	}
	for(int i = 0; i < (int)a.size(); i++) {
		int x = a[i].first,y = a[i].second;
		if(topo[x] < topo[y]) {                                         
			cout  << x << " " << y << "\n";
		}
		else cout << y << " " << x << "\n";
	}
	
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