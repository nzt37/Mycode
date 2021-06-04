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

int n,m,s,t;
struct node{
	int v,w,next;
}e[maxn];
int dis[maxn],head[maxn],cnt,vis[maxn];
void addedge(int u,int v,int w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;
}
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijisktra() {
	dis[s] = 0;
	q.push(make_pair(0,s));
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i ; i = e[i].next) {
			int v = e[i].v;
			if(dis[v] > dis[x] + e[i].w) {
				dis[v] = dis[x] + e[i].w;
				q.push(make_pair(dis[v],v));
			} 
		}
	}
}
int main() {
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	CLR(dis,0x3f3f3f3f);
	dijisktra();
	cout << dis[t] << "\n";
	return 0;
}
/*
10 20 9 4
5 6 308
8 10 696
4 2 569
8 6 471
1 2 874
5 3 130
4 5 804
8 9 89
10 4 717
10 9 41
7 6 998
1 6 639
7 9 650
7 8 339
3 1 597
9 1 622
7 10 2
5 1 4
1 4 372
1 10 163
*/