#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m,f[maxn],d[maxn];
struct node{
	int u,v,w;
}e[maxn<<2];
int find(int x) {
	if(x == f[x]) {
		return x;
	}
	return f[x] = find(f[x]);
}
void  merge(int x,int y) {
	if(find(x) != find(y)) {
		f[find(x)] = find(y);
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}	
	sort(e + 1,e+1+m, [](node a,node b){
		return a.w < b.w;
	});
	int ans = 0;
	int tot = 0;
	for(int i = 1; i <= n; i++ ) f[i] = i;
	for(int i = 1; i <= m; i++) {
		if(find(e[i].u) != find(e[i].v)) {
			// d[i] = e[i].w;
			ans = e[i].w;
			merge(e[i].u,e[i].v);
			tot++;
			if(tot == n-1) break;
		}
	}
	// for(int i = 1; i <= n; i++ ) {
	// 	ans = max(ans,d[i]);
	// }
	cout << ans << "\n";
	return 0;
}