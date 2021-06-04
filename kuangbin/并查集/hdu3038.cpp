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
int f[maxn],v[maxn];
int find(int x) {
	if(x == f[x]) return x;
	int t = find(f[x]);
	v[x] += v[f[x]];
	return f[x] = t;
}
void merge(int x,int y,int w) {
	int fx = find(x);
	int fy = find(y);
	f[fx] = fy;
	v[fx] = w + v[y] - v[x];
}
void init() {
	
}
int main() {
	while(cin >> n >> m) {
		//flag = 1;
		int ans = 0;
		for(int i = 0 ; i< maxn; i++) 
			f[i] = i,
			v[i] = 0;
		
		for(int i = 1; i <= m; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			x--;
			int fx = find(x);
			int fy = find(y);
			if(fx == fy) {
				if(v[x] - v[y] != z) ans++;
			}
			else 
			merge(x,y,z);
		}
		cout << ans << "\n";
	}	
	return 0;
}