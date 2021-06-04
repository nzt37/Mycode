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
int val_x[maxn],val_y[maxn],f[maxn],a[maxn],b[maxn],ns[maxn],ew[maxn];
int find(int x) {
	if(x == f[x]) return x;
	int t = find(f[x]);
	val_x[x] += val_x[f[x]];
	val_y[x] += val_y[f[x]];
	return f[x] = t;
}
void merge(int x,int y,int w1,int w2) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		f[fx] = fy;
		val_x[fx] = w1+val_x[y]-val_x[x];
		val_y[fx] = w2+val_y[y]-val_y[x];
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		char ch;
		int w;
		cin >> a[i] >> b[i] >> w >> ch;
		if(ch == 'N') ns[i] = w;
		else if(ch == 'S') ns[i] = -w;
		else if(ch == 'E') ew[i] = w;
		else ew[i] = -w; 
	}
	for(int i = 1; i <= n; i++) f[i] = i;
	int k;
	cin >> k;
	int cnt = 0;
	for(int i = 1; i <= k; i++) {
		int l,r,idx;
		cin >> l >> r >> idx;
		while(cnt < idx) {
			cnt++;
			merge(a[cnt],b[cnt],ns[cnt],ew[cnt]);
		}
		if(find(l) != find(r)) {
			cout << -1 << "\n";
			continue;
		}
		else {
			cout <<( abs(val_x[l] - val_x[r]) + abs(val_y[l] - val_y[r]))<< "\n";
		}
	}
	return 0;
}