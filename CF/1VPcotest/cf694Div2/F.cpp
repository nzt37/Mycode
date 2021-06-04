#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 3e5 + 10;

int n,m;
int head[maxn],cnt;
struct node{
	int v,next;
}edge[maxn<<1];
void addedge(int u,int v) {
	edge[++cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
int vis[maxn],tot,ans;
queue<int> q;
void bfs(int p) {
	vis[p] = 1;
	ans++;
	for(int i = head[p]; i; i = edge[i].next) {
		int v = edge[i].v;
		if(!vis[v]) {
			tot++;
			vis[v] = 2;
			q.push(v);
		}
	}
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i <= n; i++ ) {
		head[i] = -1;
		vis[i] = 0;
	}
	cnt = 0,tot=0,ans = 0;

	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		addedge(u,v);
		addedge(v,u);
	}
	//q.clear();
	q.push(1);
	vis[1] = 2;
	while(!q.empty()) {
		int x = q.front();q.pop();
		for(int i = head[x]; i; i = edge[i].next) {
			int v = edge[i].v;
			if(!vis[v]) {
				tot++;
				bfs(v);			
			}
			
		}
	}
	// cout << tot << "\n";
	if(tot != n) cout << "NO" << "\n";
	else {
		cout << "YES" << "\n";
		cout << ans << "\n";
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 1) cout << i << " ";
		}
		cout << "\n";
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
}