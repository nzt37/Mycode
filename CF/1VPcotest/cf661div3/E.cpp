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
#define int long long
const int maxn = 2e5 + 10;

int n,m;
int head[maxn],cnt;
int s[maxn],w[maxn],sum[maxn];
struct node{
	int v,w,next;
}e[maxn];
struct P{
	int id,val;
};
void addedge(int u,int v,int w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;
}
int dfs(int x,int f) {
	int ss = 0;
	int flag = 0;
	for(int i = head[x]; i ;i = e[i].next) {
		int v = e[i].v;
		if(v == f) continue;
		flag = 1;
		ss += dfs(v,x);
		w[v] = e[i].w;
		sum[v] = s[v] * e[i].w;
	}
	if(!flag) return s[x] = 1;
	else return s[x] = ss;
}
priority_queue<P> q;
bool operator < (P a,P b) {
	return (a.val - a.val/2)*s[a.id] < (b.val-b.val/2)*s[b.id];
}
void init() {
	for(int i = 1;  i <= n; i++) {
		sum[i] = w[i] = s[i] = head[i] = 0;
	}
	while(!q.empty()) {
		q.pop();
	}
}
void solve() {
	int S;
	cin >> n >> S;
	cnt = 0;
	init();
	for(int i = 1; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dfs(1,0);
	int tot = 0;
	for(int i = 2; i <= n; i++) {
		q.push(P{i,w[i]});
		tot += sum[i];
	}
	int ans = 0;
	while(tot > S) {
		int x = q.top().id;
		int y = q.top().val;
		q.pop();
		ans++;
		tot -= y * s[x] - (y/2)*s[x];
		q.push((P){x,y/2});
	}
	cout << ans << "\n";
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