#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

const int maxn = 2e5 + 10;

int n,m,x;
int head[maxn],cnt,vis[maxn],dis1[maxn],dis2[maxn],u[maxn],v[maxn],w[maxn];
struct node{
	int v,w,next;
}e[maxn<<1];
void addedge(int u, int v, int w) {
	e[++cnt].next = head[u];
	e[cnt].w = w;
	e[cnt].v = v;
	head[u] = cnt; 
}
typedef pair<int,int> P;
void dijkstra(int s) {
	CLR(dis1,0x3f3f3f3f);
	CLR(vis,0);
	priority_queue<P,std::vector<P>,greater<P> > q;
	q.push(make_pair(0,s));
	dis1[s] = 0;
	while(!q.empty()) {
		int m = q.top().second;
		q.pop();
		if(vis[m]) continue;
		vis[m] = 1;
		for(int i = head[m]; i; i = e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if(dis1[v] > (dis1[m] + w)) {
				dis1[v] = dis1[m] + w;
				q.push(make_pair(dis1[v],v));
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;
	for(int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		addedge(u[i],v[i],w[i]);
	}
	dijkstra(x);
	// dijkstra2(x);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		dis2[i] = dis1[i];
	}
	CLR(head,0);
	cnt = 0;
	for(int i = 1; i <= m; i++) {
		addedge(v[i],u[i],w[i]);
	}
	dijkstra(x);

	for(int i = 1; i <= n; i++) {
		ans = max(dis1[i]+dis2[i],ans);
	}
	cout << ans << "\n";
	return 0;
}