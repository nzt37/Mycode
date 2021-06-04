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


using namespace std;
const int maxn = 5e3 + 5;
int f[maxn][maxn];
int n,m;
void floyed() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(f[i][k] && f[k][j]) 
//				f[i][j] = (f[i][k] | f[k][j]);
					f[i][j] = 1;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;
		f[u][v] = 1;
	} 
	int ans = 0;
	floyed();
	for(int i = 1; i <= n; i++) {
		int res = 0; 
		for(int j = 1; j <= n; j++) {
			if(i != j) {
				if(f[i][j]) res++;
				if(f[j][i]) res++;
			}	
		}
		if(res == n-1) ans++;
	}
	cout << ans << "\n";
	return 0;
}
