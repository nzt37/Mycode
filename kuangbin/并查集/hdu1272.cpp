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

const int maxn = 1e6 + 10;

int n,m;
int f[maxn],vis[maxn];
int find(int x) {
	return f[x] == x ? x : (f[x] = find(f[x]));
}
void merge(int x,int y) {
	if(find(x) != find(y)) {
		f[find(y)] = find(x);
	}
}
void init() {
	for(int i = 1; i <= maxn; i++) {
		f[i] = i;
		vis[i] = 0;
	}
}
int main() {
	int flag = 1;
	init();
	while(cin >> n >> m && n != -1) {
		if(n == 0 && m == 0) {
			int tot = 0,fx = 0;
			for(int i = 1; i <= maxn; i++) {
				if(vis[i] && f[i] == i) {
					fx = 1;
					tot++;
				}
			}
			if(!fx) flag = 1;
			if(tot > 1) flag = 0;
			init();
			cout << (flag ? "Yes" : "No") << "\n"; 
			flag = 1;
		}
		else {
			vis[n] = vis[m] = 1;
			if(f[m] == f[n]) flag = 0;
			else if(f[m] != m) flag = 0;
			else merge(n,m);
		}
	}	
	return 0;
}