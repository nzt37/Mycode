#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 6;
int n,m;
int in[maxn],head[maxn],cnt;
struct ndoe{
	int v,next;
}edge[maxn << 1];
int siz[maxn],vis[maxn];
std::vector<int> e[maxn];
void addedge(int u,int v)
{
	edge[++cnt].next = head[u];
	edge[cnt].v = v;
	head[u] = cnt; 
}
int ans ;
queue<int> q,emp;
void findSize(int dep,int fa)
{
	siz[dep] = 1;
	for(int i = head[dep]; i; i = edge[i].next) {
		if(edge[i].v != fa) {
			findSize(edge[i].v,dep);
			siz[dep] += siz[edge[i].v];
		}
	}
}
void topo()
{
	for(int i = 1; i <= n; i++) {
		if(in[i] == 1) q.push(i);
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(int i = head[x]; i; i = edge[i].next) {
			
			int v = edge[i].v;
			in[v]--;
			if(in[v] == 1) {
				q.push(v);
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		if(in[i] > 1) {
			// cout << i <<  " ";
			vis[i] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			int tmp = 0;
			//cout << -1 << endl;
			for(int j = head[i]; j ;j = edge[j].next) {
				if(!vis[edge[j].v]) {
					findSize(edge[j].v,i);
					tmp += siz[edge[j].v];
					// cout << tmp << endl;
				}
			}
			ans += tmp;
			ans += tmp * (tmp-1) / 2;
			// cout << tmp << "\n";
		}
	}
	//cout << -1 << endl;
	
}
void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		in[i] = 0;
		siz[i] = 0;
		vis[i] = 0;
		head[i] = 0;
	}
	cnt = 0;
	ans = 0;
	for(int i = 1; i <= n; i++) {
		int u,v;
		cin >> u >> v;
		in[v]++;
		in[u]++;
		addedge(u,v);
		addedge(v,u);
	}
	q = emp;
	topo();
	cout << n*(n-1) - ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int T;
	cin >> T;
    while(T--) {
 		solve();   	
    }
    return 0;
}