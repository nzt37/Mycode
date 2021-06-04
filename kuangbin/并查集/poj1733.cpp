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

int n,m,a[maxn],f[maxn],v[maxn];
struct node{
	int x,y,z;
}e[maxn];
int find(int x) {
	if(x == f[x]) return x;
	int t = find(f[x]);
	v[x] ^= v[f[x]];
	return f[x] = t;
}
void merge(int x,int y,int z) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		f[fx] = fy;
		v[fx] = (v[x]^v[y]^z);
	}
}
int main() {
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		int x,y;
		string s;
		cin >> x >> y >> s;
		x--;
		a[++cnt] = x;
		a[++cnt] = y;
		e[i].x = x;
		e[i].y = y;
		e[i].z = (s == "even" ? 0 : 1); 
	}
	//cnt--;
	//cout << cnt << "\n";
	sort(a+1,a+1+cnt);
	int k = unique(a+1,a+1+cnt) - a;
	//cout << k << "\n";
	for(int i = 0 ; i <= maxn; i++) {
		v[i] = 0;
		f[i] = i;
	}
	int ans = m;
	for(int i = 1; i <= m; i++) {
		int x = lower_bound(a+1,a+1+k,e[i].x) - a;
		int y = lower_bound(a+1,a+1+k,e[i].y) - a;
		if(find(x) != find(y)) {
			merge(x,y,e[i].z);
		}
		else {
			if(e[i].z != (v[x] ^ v[y])) {
				ans = i-1;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}