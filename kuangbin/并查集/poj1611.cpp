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
int f[maxn];
int n,m;
inline int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y) {
	int a = find(x);
	int b = find(y);
	if(a != b) {
		f[a] = b;
	}
}
int main() {
	while(cin >> n >> m && n) {
		CLR(f,0);
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i <= m; i++) {
			int k,x,fx;
			cin >> k >> x;
			fx = x;
			for(int i = 2; i <= k; i++) {
				int b;
				cin >> b;
				merge(fx,b);
				// fx = b;
			}
		}
		int a = find(0);
		int ans = 0;
		for(int i = 0 ;i < n; i++) {
			int b = find(i);
			if(a == b ) ans++;
		}
		cout << ans << "\n";
	}	
	return 0;
}