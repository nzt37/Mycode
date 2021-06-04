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
struct node{
	int w,d;
}a[maxn];
int f[maxn];
int find(int x) {
	if(f[x] == x ) return x;
	return f[x] = find(f[x]);
}
bool cmp(node x,node y) {
	return x.w > y.w;
}
int main() {
	while(cin >> n) {
		int maxx = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].w >> a[i].d;
			maxx = max(maxx,a[i].d);
		}
		sort(a+1,a+1+n,cmp);
		for(int i = 1; i <= maxx; i++) {
			f[i] = i;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int x = find(a[i].d);
			if(x > 0) {
				ans += a[i].w;
				f[x] = x - 1;
			}
		}
		cout << ans << "\n";
	}	
	return 0;
}