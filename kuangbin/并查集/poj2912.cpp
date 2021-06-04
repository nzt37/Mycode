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
int f[maxn],a[maxn],b[maxn],val[maxn];
char ch[maxn];
int find(int x) {
	if(x == f[x]) return x;
	int t = find(f[x]);
	val[x] ^= val[f[x]];
	return f[x] = t;
}
void merge(int x,int y) {
	if(find(x) != find(y)) {
		f[find(x)] = find(y);
	}
}
void init() {
	for(int i = 1; i <= 3 * n; i++) {
		f[i] = i;
	}
}
inline bool ck(int i, int j)
{
	return find(i) == find(j);
}
int main() {
	while(cin >> n >> m) {
		for(int i = 0; i < m; i++) {
			cin >> a[i] >> ch[i] >> b[i];
		}
		int num = 0,pos = 0,pl = 0;
		for(int i = 0; i < n; i++) {
			init();
			int flag = 1;
			for(int j = 0; j < m; j++) {
				if(a[j] == i || b[j] == i) continue;
				if(ch[j] == '>') {
					if(find(a[j]) == find(b[j]) || find(a[j] + 2*n) == find(b[j])) {
						flag = 0;
						pos=max(pos,j+1);
						break;
					}
					else {
						merge(a[j],b[j]+n);
						merge(a[j]+n,b[j]+2*n);
						merge(a[j]+2*n,b[j]);
					}
				}
				else if(ch[j] == '=') {
					if(a[i] == b[i]) continue;
					if(find(a[j]+n) == find(b[j]+2*n) || find(a[j]+2*n) == find(b[j]) || find(a[j]) == find(b[j]+n)) {
						flag = 0;
						pos=max(pos,j+1);
						break;
					}
					else {
						merge(a[j],b[j]);
						merge(a[j]+n,b[j]+n);
						merge(a[j]+2*n,b[j]+2*n);
					}
				}
				else {
					if(find(a[j]) == find(b[j]) || find(a[j]+2*n) == find(b[j]) || find(a[j]+n) == find(b[j] + 2*n)) {
						flag = 0;
						pos=max(pos,j+1);
						break;
					}
					else {
						merge(a[j],b[j]+2*n);
						merge(a[j]+n,b[j]);
						merge(a[j]+2*n,b[j]+n);
					}
				}
			}
			if(flag) num++,pl=i;
		}
		if(n==1)  pos=0;
       if(num>1)  printf("Can not determine\n");
       else if(num==0)  printf("Impossible\n");
       else printf("Player %d can be determined to be the judge after %d lines\n",pl,pos);		
	}
	

	return 0;
}