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

const int maxn = 2e5 + 10;

int n,m,q;
int head[maxn],cnt;
int dis[maxn][2],vis[maxn][2];
struct node{
	int v,next,w;
}e[maxn<<1];
void add(int u,int v,int w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;
}
void dijsktea() {
	priority_queue<pii,vector<pii>,greater<pii> > q;
	CLR(dis,0x3f);
	dis[1][0] = 0;
	// dis[1][1] = 0;
	vis[1][0] = 1;
	q.push(make_pair(0,1));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		for(int i = head[u]; i ; i = e[i].next) {
			int v = e[i].v;
			if(dis[v][0] > dis[u][1] + 1) {
				dis[v][0] = dis[u][1] + 1;
				if(!vis[v][0]){
					vis[v][0] = 1;
					q.push(make_pair(dis[v][0],v));
				}
			}
			if(dis[v][1] > dis[u][0] + 1) {
				dis[v][1] = dis[u][0] + 1;
				if(!vis[v][1]){
					vis[v][1] = 1;
					q.push(make_pair(dis[v][1],v));
				}
			}
		}
	}

}
int main() {
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v,1);
		add(v,u,1);
	}
	dijsktea();
	
	while(q--) {
		int a,l;
		cin >> a >> l;
		if(!head[1]) {
			cout << "No" << "\n";
		}
		else if(dis[a][l%2] <= l) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	return 0;
}