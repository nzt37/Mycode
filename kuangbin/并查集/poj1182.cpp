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

const int maxn = 5e4+10 + 10;
int n,m;
int f[maxn*3];
int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		f[fx] = fy; 
	}
}
int main() {

	
	scanf("%d%d",&n,&m);
	int ans = 0;
	for(int i = 1; i <= 3 * n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) {
		int a,x,y;
		scanf("%d%d%d",&a,&x,&y);
		if(x > n || y > n) {  ans++;continue;}
		//if(x == y) {  ans++; continue;}
		if(a == 1) {
			if(find(x + n) == find(y) || find(x + 2*n) == find(y)) {
				ans++;
				continue;
			} 
			else {
				merge(x,y);
				merge(x + n,y + n);
				merge(x + 2*n,y + 2*n);
			}
		}
		else {
			if(find(x) == find(y) || find(x + 2*n) == find(y)) {
				ans++;
				continue;
			}
			else {
				merge(x+n,y);
				merge(x+2*n,y+n);
				merge(x,y+2*n);
			}
		}
	}	
	printf("%d\n",ans);
	return 0;
}