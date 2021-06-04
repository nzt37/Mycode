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

const int maxn = 505;
int head[maxn],cnt;
int f[maxn][maxn];
int n,m;
bool floyed() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(f[i][j] > f[i][k] + f[k][j])
				f[i][j] = f[i][k] + f[k][j];
				// if(i == j) { if(f[i][i] < 0) return false;}
			}
			if(f[i][i] < 0) return false;
		}
	}
	return true;
}
void solve() {
	 int w;
	 CLR(f,0x3f3f3f3f);
	 for(int i = 0; i <= n; i++) { f[i][i] = 0;}
	 cin >> n >> m >> w;
	 for(int i = 0; i < m; i++) {
	 	int u,v,w;
	 	cin >> u >> v >> w;
	 	if(w < f[u][v])
	 	f[v][u] = f[u][v] = w;
	 	// f[v][u] = w; 
	 }
	 for(int i = 0; i < w; i++) {
	 	int u,v,w;
	 	cin >> u >> v >> w;
	 	f[u][v] = -w;
	 }
	 if(!floyed()) {
	 	cout << "YES" << "\n";
	 }else {
	 	cout << "NO" << "\n";
	 }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}