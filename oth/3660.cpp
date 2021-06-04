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


const int maxn = 4e3 + 80;

int n,m;
int a[maxn][maxn];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		a[u][v]++;
	}	
	int ans = 0;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(a[i][k] && a[k][j])
					a[i][j] = 1;
			}
				
		}
	}
	for(int i = 1; i <= n; i++) {
		int flag = 1;
		for(int j = 1; j <= n; j++) {
			if(i != j && !a[i][j] && !a[j][i]) {
				flag = 0;
				break;
			}
		}
		if(flag) ans++;
	}
	cout << ans << "\n";
	return 0;
}