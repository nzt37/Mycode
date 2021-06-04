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

const int maxn = 4e4 + 10;

int n,m;
struct node {
	int v,next;
}e[maxn];
int f[maxn][2],in[maxn];
int head[maxn],cnt;
void add(int u,int v) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
void dfs(int u) {
	f[u][1] = 1;
	for(int i = head[u]; i ;i = e[i].next) {
		int v = e[i].v;
		// if(u == v) continue;
		dfs(v);
		f[u][0] += f[v][1];
		f[u][1] += min(f[v][0],f[v][1]);
	}
}
int main() {
	while(cin >> n) {
		CLR(f,0);
		CLR(head,0);
		CLR(in,0);
		cnt = 0;
		for(int j = 1; j <= n; j++) {
			int a,b;
            scanf("%d:(%d)",&a,&b);
            for(int i=1; i<=b; i++)
            {
                int c;
                scanf("%d",&c);
                in[c]++;
                add(a,c);
            }
		}
		int t = -1;
		for(int i = 0; i <= n; i++) {
			if(!in[i]) {
				t = i;
				break;
			}
		}
		dfs(t);
		// cout << t << "\n";
		cout << min(f[t][0],f[t][1]) << "\n";
	}	
	return 0;
}