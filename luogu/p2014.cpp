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

int n,m;
int k[maxn],s[maxn];
int head[maxn],cnt;
int f[330][330];
struct node{
	int v,w,next;
}e[maxn];
void addedge(int u,int v,int w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;
}
void dfs(int u) {
	for(int i = head[u]; i ; i = e[i].next) {
		int v = e[i].v;
		// if(v == u) continue;
		dfs(v);
		for(int j = m + 1; j >= 1; j--) {
			for(int k = 0; k < j; k++) {
				f[u][j] = max(f[u][j],f[u][j-k]+f[v][k]);
				// cout << u << " " << v << " " << f[u][j] << "\n";
			}
		}
		// f[u] = max(f[u],f[v]+s[v]);
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> k[i] >> f[i][1];
		// if(k[i] == 0) {
		// 	f[i][0] = f[i][1] = s[i];
		// }
		addedge(k[i],i,s[i]);
	}
	dfs(0);
	cout << f[0][m+1] << "\n";
	return 0;
}