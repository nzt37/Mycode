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

int n,m,f[maxn],vis[maxn];
void init() {
	for(int i = 0; i < maxn; i++) {
		f[i] = i;
		vis[i] = 0;
	}
}
int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y) {
	int a = find(x);
	int b = find(y);
	if(a != b) {
		f[b] = a;
	}
}
int main() {
	int an = 0;
	int flag = 1;
	init();
	while(cin >> n >> m && (n != -1)) {
		if(!(!n && !m)) {
			vis[n] = vis[m] = 1;
			if(f[m] == f[n]) flag = 0;
			else if(f[m] != m) flag = 0;
			else merge(n,m);
		}
		else {
			int cnt = 0;
			int tot = 1,istree = 0;
			for(int i = 1; i < maxn; i++) {
				if(vis[i] && f[i] == i) {
					cnt++;
					tot = 0;
					if(cnt > 1) {
						istree= 1;
						break;
					}
				}
				
			}
			if(tot) flag = 1;
			if(istree) flag = 0;
			// if(cnt > 1) flag = 0;
			if (flag) printf("Case %d is a tree.\n", ++an);
			else printf("Case %d is not a tree.\n", ++an);
			init();
			flag = 1;
		}
		
	}	
	return 0;
}