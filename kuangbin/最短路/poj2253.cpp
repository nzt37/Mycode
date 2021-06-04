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

const int maxn = 2e4 + 10;
typedef pair<double,int> P;
int n,m;
int head[maxn],cnt;
struct node{
	int v,next;
	double w;
}e[maxn<<1];
int x[maxn],y[maxn],vis[maxn],tot;
double dis[maxn];
void addedge(int u,int v,double w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;
}
double cal(int i,int j)
{
	double xx=x[i]-x[j],yy=y[i]-y[j];
	return sqrt(xx*xx+yy*yy);
}
void dijsktra() {
	for(int i = 0; i <= 200; i++) dis[i] = 3000;
	CLR(vis,0);
	priority_queue<P,std::vector<P>,greater<P> > q;
	// vis[1] = 1;
	q.push(make_pair(0,1));
	dis[1] = 0;
	while(!q.empty()) {
		int m = q.top().second;
		q.pop();
		// DEBUG(1);
		if(vis[m]) continue;
		vis[m] = 1;
		for(int i = head[m]; i; i = e[i].next) {
			int v = e[i].v;
			// cout << "v " << v  << 'u' << m << "\n";
			// DEBUG(2);
			// cout << dis[v] << " " << max(dis[m],e[i].w) << "\n";
			if((dis[v] >= max(dis[m],e[i].w)) && !vis[v]) {

				dis[v] = max(dis[m],e[i].w);
				// if(!vis[v])
				q.push(make_pair(dis[v],v));
				// cout << dis[v] << " dfsfd" << "\n";
			}
		}
	}

}
int main() {
	while((cin >> n) && n) {
		CLR(head,0);
		cnt = 0;
		for(int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
		}
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				// double w = sqrt((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]));
				double w = cal(i,j);
				addedge(i,j,w);
				addedge(j,i,w);
			}
		}
		// for(int i = 1; i <= cnt; i++) {
		// 	printf(" %d %.3lf\n",e[i].v,e[i].w);
		// }
		dijsktra();
		tot++;
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",tot,dis[2]);
	}
	return 0;
}