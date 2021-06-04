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
int f[maxn],val[maxn];
int find(int x) {
	if(x == f[x]) return x;
	int t = find(f[x]);
	val[x] ^= val[f[x]];
	return f[x] = t;
}
void  merge(int x,int y,int z) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		f[fx] = fy;
		val[fx] = (val[x]^val[y]^z);
	}
}
int main() {	
	int T;
	cin >> T;
	int an = 0;
	while(T--) {
		scanf("%d%d",&n,&m);
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			f[i] = i;
			val[i] = 0;
		}
		for(int i = 1; i <= m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			
			if(find(a) != find(b)) {
				merge(a,b,1);
			}
			else {
				if((val[a] ^ val[b] )== 0) flag = 1;
			}
		}
		 printf("Scenario #%d:\n",++an);
    if(flag) printf("Suspicious bugs found!\n");
    else printf("No suspicious bugs found!\n");
    printf("\n");
	}	
	return 0;
}