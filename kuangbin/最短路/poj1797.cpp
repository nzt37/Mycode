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

const int maxn = 4e5 + 10;

int n,m;
int head[maxn],cnt;
int dis[maxn],vis[maxn];
struct node{
	int v,w,next;
}e[maxn<<1];
void add(int u,int v,int w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;  
}
typedef pair<int,int> P;
void dijsktra() {
	priority_queue <P> q;
	CLR(vis,0);
	CLR(dis,0);
	dis[1] = 1e9;
	q.push(make_pair(0,1));
	// vis[1] = 1;
	while(!q.empty()) {
		int m = q.top().second;
		q.pop();
		if(vis[m]) continue;
		vis[m] = 1;
		for(int i = head[m]; i ;i = e[i].next) {
			int v = e[i].v;
			if(dis[v] < min(dis[m],e[i].w)) {
				dis[v] = min(dis[m],e[i].w);
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	int o = 0;
	while(T--) {
		cin >> n >> m;
		CLR(head,0);
		cnt = 0;
		for(int i = 1; i <= m; i++) {
			int u,v,w;
			cin >> u >> v >> w;
			add(u,v,w);
			add(v,u,w);
		}
		dijsktra();
		o++;
		printf("Scenario #%d:\n",o);
        printf("%d\n",dis[n]);
        printf("\n");
	}
	return 0;
}