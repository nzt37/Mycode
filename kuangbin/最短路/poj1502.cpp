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

const int maxn = 110;
const int inf = 0x3f3f3f3f;
int n,m;
int cnt,head[maxn],dis[maxn],vis[maxn];
struct node{
	int v,w,next;
}edge[maxn<<1];

void addedge(int u,int v,int w) {
	edge[++cnt].next = head[u];
	edge[cnt].v = v;
	edge[cnt].w = w;
	head[u] = cnt;
}
typedef pair<int,int> P;
priority_queue<P,std::vector<P> , greater<P> > q;
void dijkatra() {
	CLR(dis,0x3f);
	dis[1] = 0;
	q.push(make_pair(0,1));
	while(!q.empty()) {
		int m = q.top().second;
		q.pop();
		if(vis[m]) continue;
		vis[m] = 1;
		for(int i = head[m]; i; i = edge[i].next) {
			int v = edge[i].v;
			if(dis[v] > edge[i].w +dis[m]) {
				dis[v] = edge[i].w +dis[m];
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main() {
	cin >> n;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			char s[8];
			scanf("%s",s);
			if(s[0] == 'x') continue;
			int w = atoi(s);
			addedge(i,j,w);
			addedge(j,i,w);
		}
	}
	dijkatra();
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		ans = max(ans,dis[i]);
		// cout << dis[i] << "\n";
	}
	cout << ans << "\n";
	return 0;
}